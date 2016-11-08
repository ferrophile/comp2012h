#include "ExtMoney.h"
#include <iostream>
using namespace std;

void ExtMoneyType::Print() const {
	cout << this->DollarsAre() << " " << this->CentsAre() << " " << currency << " ";
}

string ExtMoneyType::CurrencyIs() const {
	return currency;
}

void ExtMoneyType::Initialize(long newDollars, long newCents, string newCurrency) {
	this->MoneyType::Initialize(newDollars, newCents);
	currency = newCurrency;
}

ExtMoneyType::ExtMoneyType()
: MoneyType(), currency("") {}

ExtMoneyType::ExtMoneyType(long newDollars, long newCents, string newCurrency)
: MoneyType(newDollars, newCents), currency(newCurrency) {}
