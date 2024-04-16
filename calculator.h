#ifndef CALCULATOR_H
#define CALCULATOR_H

template <typename Z>
class Calculator{

    Z* determinedCurrency;
    Z* ticketsForCalculator;
    double moneyGiven;

    public:
        Calculator();
        Calculator(Z, Z, double);
        Calculator(const Calculator&);

        Z getMoneyGiven();
        void setMoneyGiven(double);

        Z calculation(Z*, Z*);
        double calculation(double);
};

template <class Z>
Calculator<Z>::Calculator(){
    determinedCurrency = 0;
    ticketsForCalculator = 0;
    moneyGiven = 0;
}
template <class Z>
Calculator<Z>::Calculator(Z newDeterminedCurrency, Z newTicketsForCalculator, double newMoneyGiven){
    determinedCurrency = newDeterminedCurrency;
    newTicketsForCalculator = ticketsForCalculator;
    moneyGiven = newMoneyGiven;
}
template <class Z>
Calculator<Z>::Calculator(const Calculator& old){
    determinedCurrency = old.determinedCurrency;
    ticketsForCalculator = old.ticketsForCalculator;
    moneyGiven = old.moneyGiven;
}

template <class Z>
Z Calculator<Z>::getMoneyGiven(){
    return moneyGiven;
}
template <class Z>
void Calculator<Z>::setMoneyGiven(double newMoneyGiven){
    moneyGiven = newMoneyGiven;
}

//operator overload
template <class Z>
Z Calculator<Z>::calculation(Z* determinedCurrency, Z* ticketsForCalculator){
    Z ticketsCalculation;

    ticketsCalculation = ticketsForCalculator - determinedCurrency;

    return ticketsCalculation;
}
//operator overload
template <class Z>
double Calculator<Z>::calculation(double moneyGiven){
    double changeCalculationTotal;

    changeCalculationTotal = calculation(determinedCurrency, ticketsForCalculator) - moneyGiven;

    return changeCalculationTotal;
    
}

#endif