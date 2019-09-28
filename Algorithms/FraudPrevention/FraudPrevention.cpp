#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <assert.h>

//https://www.hackerrank.com/challenges/fraud-prevention

class Order; struct OrderCmp;
typedef std::map<std::string, std::string> Token_Map;
typedef std::set<Order*, OrderCmp> Fraud_List;

class ItemProcessor {
public:
	virtual std::string process(std::string item) = 0;
protected:
	// Converts a string to lower case only
	std::string to_lower(std::string s) {
		std::transform(s.begin(), s.end(), s.begin(), tolower);

		return s;
	}

	// Replaces the given token's key, if found in string s, with the corresponding value (key -> value)
	std::string replace_tokens(std::string s, const Token_Map& tok_map) {
		for (auto it : tok_map) {
			auto pos = s.find(it.first);

			// The current string key value was found
			if (pos != std::string::npos) {
				// Erase the string that was found
				s.erase(pos, it.first.length());
				// Replace it with the value from the map
				s.insert(pos, it.second);

				// Break out of the loop, as it is only possible for one instance to be replaced
				break;
			}
		}

		return s;
	}
};
// Passes the input straight through without any modification
class PassiveProcessor : public ItemProcessor {
	virtual std::string process(std::string item) {
		return item;
	}
};
class EmailProcessor : public ItemProcessor {
public:
	virtual std::string process(std::string email) {
		// E-mail addresses are case insensitive, . before @ are ignored,
		// anything after a +, before @ is ignored.

		// Find location of @
		auto at_pos = email.find('@');
		auto at_pos_it = email.begin() + at_pos;
		assert(at_pos != std::string::npos);

		auto plus_pos = std::find(email.begin(), at_pos_it, '+');

		// A plus sign was found before the @
		if (plus_pos != at_pos_it) {
			// Remove everything after and including the +
			email.erase(plus_pos, at_pos_it);
		}

		// Remove any . before the @
		email.erase(std::remove_if(email.begin(), at_pos_it, [](const char c) { return c == '.'; }), at_pos_it);

		// Convert the remaining e-mail address to lower case
		return to_lower(email);
	}
};
class AddressProcessor : public ItemProcessor {
public:
	virtual std::string process(std::string address) {
		// Case insensitive, St. == Street, Rd. = Road
		address = to_lower(address);
		address = replace_tokens(address, ADDRESSES_MAP);
		return address;
	}
private:
	static Token_Map ADDRESSES_MAP;
};
Token_Map AddressProcessor::ADDRESSES_MAP = {	{ "rd.", "road" },
												{ "st.", "street" } };

class CityProcessor : public ItemProcessor {
public:
	virtual std::string process(std::string city) {
		city = to_lower(city);
		return city;
	}
};

class StateProcessor : public ItemProcessor {
public:
	virtual std::string process(std::string state) {
		state = to_lower(state);
		state = replace_tokens(state, STATES_MAP);
		return state;
	}
private:
	static Token_Map STATES_MAP;
};
Token_Map StateProcessor::STATES_MAP = { { "il", "illinois" },
{ "ny", "new york" },
{ "ca", "california" } };

class ZIPProcessor : public ItemProcessor {
public:
	virtual std::string process(std::string zip) {
		zip = to_lower(zip);
		// Remove dashes
		zip.erase(std::remove_if(zip.begin(), zip.end(), [](const char c) { return c == '-'; }), zip.end());
		return zip;
	}
};

// Represents a single order
class Order {
public:
	// Stores a list of potential fields that an order may contain
	enum class Field {
		ORDER_ID, DEAL_ID, EMAIL_ADDRESS, STREET_ADDRESS, CITY, STATE, ZIPCODE, CARD_NUMBER
	};

	Order() {}

	void add_field(const Order::Field& field, const std::string& value) {
		order_values[field] = value;
	}

	std::string get_field(Order::Field field) {
		return order_values[field];
	}
private:
	// Stores all data about this particular order as key value pairs
	// New fields can easily be added via new enum value
	std::map<Order::Field, std::string> order_values;
};
// Compares the mathematical ordering of two particular orders
struct OrderCmp {
	bool operator()(Order* order1, Order* order2) {
		int order1_id = std::stoi(order1->get_field(Order::Field::ORDER_ID));
		int order2_id = std::stoi(order2->get_field(Order::Field::ORDER_ID));
		return order1_id < order2_id;
	}
};
class OrderProcessor {
	// Stores a single field to be input, and how it is processed
	struct Input {
		Order::Field field;
		ItemProcessor* processor;
	};
public:
	OrderProcessor(char delim) {
		m_delim = delim;
	}

	virtual ~OrderProcessor() {
		for (Input i : inputs) {
			delete i.processor;
		}
	}

	void add_field(Order::Field field, ItemProcessor* processor) {
		inputs.push_back({ field, processor });
	}

	// Generates an order from a line of input
	Order* generate_order(std::string input) {
		std::stringstream ss(input);
		std::string temp;

		Order* order = new Order();
		for (Input input : inputs) {
			std::getline(ss, temp, m_delim);
			order->add_field(input.field, input.processor->process(temp));
		}
		
		return order;
	}
private:
	char m_delim;
	std::vector<Input> inputs;
};
// Searches through a set of orders for the given criteria,
// to extract a set of all fraudulent orders
class FraudDetector {
public:
	FraudDetector(const std::vector<Order*>& orders) {
		m_orders = orders;
	}

	// Adds a field which must be identical amongst a pair of orders,
	// for them to be considered fraudulent
	void add_field_identical(Order::Field field) {
		m_field_identical.push_back(field);
	}

	// Adds a field which must be different amongst a pair of orders,
	// for them to be considered fraudulent
	void add_field_different(Order::Field field) {
		m_field_different.push_back(field);
	}

	Fraud_List get_fraudulent_orders() {
		// Concatenation of similar fields -> orders
		std::map<std::string, std::vector<Order*>> fraud_map;
		Fraud_List fraudulent_orders;
		for (Order* order : m_orders) {
			std::string key = "";
			for (Order::Field field : m_field_identical) {
				key += order->get_field(field);
			}

			// If there are other orders which match the required fields
			if (fraud_map[key].size() > 0) {
				bool atleast_one_fraudulent = false;
				// Check every other order which has the same key as order : m_orders
				// to see if they also have the required differences
				for (Order* potential_fraud : fraud_map[key]) {
					bool different = true;

					for (Order::Field field : m_field_different) {
						// One of the difference required fields, does not contain a difference
						// (therefore is not fraudulent)
						if (order->get_field(field) == potential_fraud->get_field(field)) {
							different = false;
							break;
						}
					}

					// potential_fraud is fraudulent (different fields were different)
					if (different) {
						// We have found at least one fraudulent order in correspondence with order
						atleast_one_fraudulent = true;
						// Add this as a new fraudulent order to the set (may already be contained within the set)
						fraudulent_orders.insert(potential_fraud);
					}
				}

				// If we determined one other to be fraudulent with this,
				// then this too must be a fraudulent order
				if (atleast_one_fraudulent) {
					fraudulent_orders.insert(order);
				}
			}

			// Add this order to the map by its key, so it can later be compared for fraud too
			fraud_map[key].push_back(order);
		}

		return fraudulent_orders;
	}
private:
	// Stores a list of orders which are to be checked for fraud
	std::vector<Order*> m_orders;
	// Stores fields which must be identical for an order to be considered fraudulent
	std::vector<Order::Field> m_field_identical;
	// Stores fields which must be different for an order to be considered fraudulent
	std::vector<Order::Field> m_field_different;
};

// Prints a list in comma format (with no trailing comma)
void pretty_print(const Fraud_List& orders) {
	auto it = orders.begin();
	std::cout << (*it++)->get_field(Order::Field::ORDER_ID);
	while (it != orders.end()) {
		std::cout << "," << (*it)->get_field(Order::Field::ORDER_ID);
		it++;
	}
	std::cout << std::endl;
}

int main() {
	int num_records;
	std::cin >> num_records;
	
	// Specify the fields that are to be read in, and how they are processed
	// Note: order is important
	OrderProcessor processor(',');
	processor.add_field(Order::Field::ORDER_ID, new PassiveProcessor());
	processor.add_field(Order::Field::DEAL_ID, new PassiveProcessor());
	processor.add_field(Order::Field::EMAIL_ADDRESS, new EmailProcessor());
	processor.add_field(Order::Field::STREET_ADDRESS, new AddressProcessor());
	processor.add_field(Order::Field::CITY, new CityProcessor());
	processor.add_field(Order::Field::STATE, new StateProcessor());
	processor.add_field(Order::Field::ZIPCODE, new ZIPProcessor());
	processor.add_field(Order::Field::CARD_NUMBER, new PassiveProcessor());

	std::vector<Order*> orders;
	std::string s;
	std::getline(std::cin, s); // Consume the extra new line
	for (int i = 0; i < num_records; i++) {
		std::getline(std::cin, s);
		orders.push_back(processor.generate_order(s));
	}

	// Checks for same e-mail & deal, but different credit card
	FraudDetector fd_1(orders);
	fd_1.add_field_identical(Order::Field::EMAIL_ADDRESS);
	fd_1.add_field_identical(Order::Field::DEAL_ID);
	fd_1.add_field_different(Order::Field::CARD_NUMBER);
	auto forders_1 = fd_1.get_fraudulent_orders();

	// Checks for same address & deal, but different credit card
	FraudDetector fd_2(orders);
	fd_2.add_field_identical(Order::Field::STREET_ADDRESS);
	fd_2.add_field_identical(Order::Field::DEAL_ID);
	fd_2.add_field_different(Order::Field::CARD_NUMBER);
	auto forders_2 = fd_2.get_fraudulent_orders();
	
	// Append the two lists
	forders_1.insert(forders_2.begin(), forders_2.end());

	// Output all fraudulent orders
	pretty_print(forders_1);

	return 0;
}