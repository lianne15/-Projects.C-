#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

// Function to get the exchange rate for a given currency
double getExchangeRate(const string &fromCurrency, const string &toCurrency) {
    // Hardcoded exchange rates (from USD)
    map<pair<string, string>, double> exchangeRates = {
        {{"USD", "EUR"}, 0.94},  // 1 USD to EUR
        {{"USD", "GBP"}, 0.81},  // 1 USD to GBP
        {{"USD", "KES"}, 150.0}, // 1 USD to KES
        {{"USD", "INR"}, 83.0},  // 1 USD to INR
        {{"EUR", "USD"}, 1.06},  // 1 EUR to USD
        {{"GBP", "USD"}, 1.23},  // 1 GBP to USD
        {{"KES", "USD"}, 1/150.0},  // 1 KES to USD
        {{"INR", "USD"}, 1/83.0},  // 1 INR to USD
    };

    if (exchangeRates.find({fromCurrency, toCurrency}) != exchangeRates.end()) {
        return exchangeRates[{fromCurrency, toCurrency}];
    }

    // If no exchange rate is found, return -1
    return -1;
}

int main() {
    string fromCurrency, toCurrency;
    double amount;

    cout << "Currency Converter" << endl;
    cout << "Available currencies: USD, EUR, GBP, KES, INR" << endl;

    // Get user input for amount and currencies
    cout << "Enter the amount: ";
    cin >> amount;
    cout << "Enter the currency you want to convert from (e.g., USD, EUR, GBP, KES, INR): ";
    cin >> fromCurrency;
    cout << "Enter the currency you want to convert to (e.g., USD, EUR, GBP, KES, INR): ";
    cin >> toCurrency;

    // Get the exchange rate
    double rate = getExchangeRate(fromCurrency, toCurrency);

    if (rate != -1) {
        // Perform the conversion
        double convertedAmount = amount * rate;
        cout << fixed << setprecision(2);
        cout << amount << " " << fromCurrency << " = " << convertedAmount << " " << toCurrency << endl;
    } else {
        cout << "Exchange rate not available for these currencies!" << endl;
    }

    return 0;
}
