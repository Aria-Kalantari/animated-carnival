#include "BigNum.h"
#include <stdexcept>

BigNum::BigNum(const char* bigNum)
{
    this->setBigNum(std::string(bigNum));
}

BigNum::BigNum(const std::string& bigNum)
{
    this->setBigNum(std::string(bigNum));
}

BigNum::BigNum(const int bigNum)
{
    this->setBigNum(std::to_string(bigNum));
}

BigNum::BigNum(const long int bigNum)
{
    this->setBigNum(std::to_string(bigNum));
}

BigNum::BigNum(const long long int bigNum)
{
    this->setBigNum(std::to_string(bigNum));
}


void BigNum::setBigNum(const std::string& bigNum)
{
    std::string notConstBigNum = bigNum;

    if(notConstBigNum.length() > 1)
        for(int i = 1; i < notConstBigNum.length(); ++i)
            if((notConstBigNum[i] < '0' || notConstBigNum[i] > '9') && notConstBigNum[i] != '.')
                throw std::invalid_argument("BigNum takes only integers.");

    if(((notConstBigNum[0] < '0' && (notConstBigNum[0] != '-' && notConstBigNum[0] != '+' && notConstBigNum[0] != '.')) || 
         notConstBigNum[0] > '9') && !(notConstBigNum.empty()))
        throw std::invalid_argument("BigNum takes only integers.");

    for(int i = 0; i < notConstBigNum.length(); ++i)
        if(notConstBigNum[i] == '.')
        {
            notConstBigNum = notConstBigNum.substr(0, i);
            break;
        }

    if(notConstBigNum[0] == '+')
        notConstBigNum = notConstBigNum.substr(1);

    this->bigNum = notConstBigNum; 
}

const std::string& BigNum::getBigNum(void) const
{
    return this->bigNum;
}


BigNum& BigNum::operator+=(const BigNum& rightNum)
{
    if(this->bigNum >= "0" && rightNum.bigNum >= "0")
        *this = this->plus(*this, rightNum);

    else if(this->bigNum <= "0" && rightNum.bigNum <= "0")
    {
        BigNum thisTemp;
        BigNum rightTemp;
        thisTemp.bigNum = this->bigNum.substr(1);
        rightTemp.bigNum = rightNum.bigNum.substr(1);
        *this = this->plus(thisTemp, rightNum);
        if(this->bigNum != "0")
        {
            BigNum sumTemp;
            sumTemp.bigNum = '-' + this->bigNum;
            *this = sumTemp;
        }
    }

    else if(this->bigNum < "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp;
        thisTemp.bigNum = this->bigNum.substr(1);
        *this = this->minus(thisTemp, rightNum);
        if(thisTemp > rightNum && this->bigNum != "0")
        {
            BigNum sumTemp;
            sumTemp.bigNum = '-' + this->bigNum;
            *this = sumTemp;
        }
    }

    else if(this->bigNum < "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp;
        thisTemp.bigNum = this->bigNum.substr(1);
        *this = this->minus(thisTemp, rightNum);
        if(thisTemp > rightNum && this->bigNum != "0")
        {
            BigNum sumTemp;
            sumTemp.bigNum = '-' + this->bigNum;
            *this = sumTemp;
        }
    }

    return *this;
}

BigNum& BigNum::operator-=(const BigNum& rightNum)
{
    if(this->bigNum >= "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp = *this;
        *this = this->minus(*this, rightNum);
        if(rightNum > thisTemp && this->bigNum != "0")
        {
            BigNum differenceTemp = '-' + this->bigNum;
            *this = differenceTemp;
        }
    }

    else if(this->bigNum < "0" && rightNum.bigNum < "0")
    {
        BigNum thisTemp = this->bigNum.substr(1);
        BigNum rightTemp = rightNum.bigNum.substr(1);
        *this = this->minus(thisTemp, rightTemp);
        if(thisTemp > rightTemp && this->bigNum != "0")
        {
            BigNum differenceTemp = '-' + this->bigNum;
            *this = differenceTemp;
        }
    }
    
    else if(this->bigNum >= "0" && rightNum.bigNum < "0")
    {
        BigNum rightTemp;
        rightTemp.bigNum = rightNum.bigNum.substr(1);
        *this = this->plus(*this, rightTemp);
    }

    else if(this->bigNum < "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp;
        thisTemp.bigNum = this->bigNum.substr(1);
        *this = this->plus(thisTemp, rightNum);
        if(this->bigNum != "0")
        {
            BigNum differenceTemp = '-' + this->bigNum;
            *this = differenceTemp;
        }
    } 

    return *this;   
}

BigNum& BigNum::operator*=(const BigNum& rightNum)
{
    if(this->bigNum >= "0" && rightNum.bigNum >= "0")
        *this = this->multiply(*this, rightNum);

    if(this->bigNum < "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp = this->bigNum.substr(1);
        *this = multiply(thisTemp, rightNum);
        if(this->bigNum != "0")
        {
            BigNum productTemp = '-' + this->bigNum;
            *this = productTemp;
        }
    }

    if(this->bigNum >= "0" && rightNum.bigNum < "0")
    {
        BigNum rightTemp = rightNum.bigNum.substr(1);
        *this = multiply(*this, rightTemp);
        if(this->bigNum != "0")
        {
            BigNum productTemp = '-' + this->bigNum;
            *this = productTemp;
        }
    }

    if(this->bigNum < "0" && rightNum.bigNum < "0")
    {
        BigNum thisTemp = this->bigNum.substr(1);
        BigNum rightTemp = rightNum.bigNum.substr(1);
        *this = multiply(thisTemp, rightTemp);
    }
    
    return *this;
}

BigNum& BigNum::operator/=(const BigNum& rightNum)
{
    if(this->bigNum >= "0" && rightNum.bigNum >= "0")
        *this = this->divide(*this, rightNum);

    if(this->bigNum < "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp = this->bigNum.substr(1);
        *this = divide(thisTemp, rightNum);
        if(this->bigNum != "0")
        {
            BigNum quotientTemp = '-' + this->bigNum;
            *this = quotientTemp;
        }
    }

    if(this->bigNum >= "0" && rightNum.bigNum < "0")
    {
        BigNum rightTemp = rightNum.bigNum.substr(1);
        *this = divide(*this, rightTemp);
        if(this->bigNum != "0")
        {
            BigNum quotientTemp = '-' + this->bigNum;
            *this = quotientTemp;
        }
    }

    if(this->bigNum < "0" && rightNum.bigNum < "0")
    {
        BigNum thisTemp = this->bigNum.substr(1);
        BigNum rightTemp = rightNum.bigNum.substr(1);
        *this = divide(thisTemp, rightTemp);
    }
    
    return *this;
}

BigNum& BigNum::operator%=(const BigNum& rightNum)
{
    *this = modulo(*this, rightNum);
    return *this;
}


BigNum& BigNum::operator++(void)
{
    BigNum rightNum("1");

    if(this->bigNum >= "0" && rightNum.bigNum >= "0")
        *this = this->plus(*this, rightNum);

    else if(this->bigNum < "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp;
        thisTemp.bigNum = this->bigNum.substr(1);
        *this = this->minus(thisTemp, rightNum);
        if(thisTemp > rightNum && this->bigNum != "0")
        {
            BigNum sumTemp = '-' + this->bigNum;
            *this = sumTemp;
        }
    }

    return *this;
}

BigNum BigNum::operator++(int)
{
    BigNum rightNum("1");

    BigNum sum;

    if(this->bigNum >= "0" && rightNum.bigNum >= "0")
        sum = this->plus(*this, rightNum);

    else if(this->bigNum < "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp;
        thisTemp.bigNum = this->bigNum.substr(1);
        sum = this->minus(thisTemp, rightNum);
        if(thisTemp > rightNum && sum.bigNum != "0")
        {
            BigNum sumTemp = '-' + sum.bigNum;
            sum = sumTemp;
        }
    }

    return sum;
}

BigNum& BigNum::operator--(void)
{
    BigNum rightNum("1");

    if(this->bigNum >= "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp = *this;
        *this = this->minus(*this, rightNum);
        if(rightNum > thisTemp && this->bigNum != "0")
        {
            BigNum differenceTemp = '-' + this->bigNum;
            *this = differenceTemp;
        }
    }

    else if(this->bigNum < "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp;
        thisTemp.bigNum = this->bigNum.substr(1);
        *this = this->plus(thisTemp, rightNum);
        if(this->bigNum != "0")
        {
            BigNum differenceTemp = '-' + this->bigNum;
            *this = differenceTemp;
        }
    } 

    return *this; 
}

BigNum BigNum::operator--(int)
{
    BigNum rightNum("1");

    BigNum difference;

    if(this->bigNum >= "0" && rightNum.bigNum >= "0")
    {
        difference = this->minus(*this, rightNum);
        if(rightNum > *this && difference.bigNum != "0")
        {
            BigNum differenceTemp = '-' + difference.bigNum;
            difference = differenceTemp;
        }
    }

    else if(this->bigNum < "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp;
        thisTemp.bigNum = this->bigNum.substr(1);
        difference = this->plus(thisTemp, rightNum);
        if(difference.bigNum != "0")
        {
            BigNum differenceTemp = '-' + difference.bigNum;
            difference = differenceTemp;
        }
    }

    return difference;
}


char& BigNum::operator[](const int index)
{
    BigNum dummyNum = *this;

    if(this->bigNum[0] == '-')
        dummyNum.bigNum = dummyNum.bigNum.substr(1);

    std::string reversedNum = std::string(dummyNum.bigNum.rbegin(), dummyNum.bigNum.rend());

    if(index >= 1 && index <= dummyNum.bigNum.length())
        return reversedNum[index - 1];
    else
        throw std::out_of_range("Index is out of range.");
}

const char& BigNum::operator[](const int index) const
{
    BigNum dummyNum = *this;

    if(this->bigNum[0] == '-')
        dummyNum.bigNum = dummyNum.bigNum.substr(1);

    std::string reversedNum = std::string(dummyNum.bigNum.rbegin(), dummyNum.bigNum.rend());

    if(index >= 1 && index <= dummyNum.bigNum.length())
        return reversedNum[index - 1];
    else
        throw std::out_of_range("Index is out of range.");
}


void BigNum::printWithDelimeter(void) const
{
    std::string reversedBigNumWithDelimeter;
    int count = 0;

    bool checkMinus = false;

    std::string reversedBigNum = std::string(this->bigNum.rbegin(), this->bigNum.rend());

    if(reversedBigNum[reversedBigNum.length() - 1] == '-')
    {
        reversedBigNum = reversedBigNum.substr(0, reversedBigNum.length() - 1);
        checkMinus = true;
    }

    for(int i = 0; i < this->getBigNum().length(); ++i)
    {
        reversedBigNumWithDelimeter += reversedBigNum[i];

        ++count;

        if(count == 3 && i <= this->getBigNum().length() - 3)
        {
            reversedBigNumWithDelimeter += ',';
            count = 0;
        }
    }

    std::string bigNumWithDelimeter = std::string(reversedBigNumWithDelimeter.rbegin(), reversedBigNumWithDelimeter.rend());

    if(checkMinus)
        bigNumWithDelimeter = "-" + bigNumWithDelimeter;    

    std::cout << bigNumWithDelimeter << std::endl;
}


BigNum::operator int(void) const
{
    return stoi(this->bigNum);
}

BigNum::operator long int(void) const
{
    return stol(this->bigNum);
}

BigNum::operator long long int(void) const
{
    return stoll(this->bigNum);
}


BigNum::operator unsigned int(void) const
{
    return stoul(this->bigNum);
}

BigNum::operator unsigned long int(void) const
{
    return stoul(this->bigNum);
}

BigNum::operator unsigned long long int(void) const
{
    return stoull(this->bigNum);
}


BigNum BigNum::plus(const BigNum& leftNum, const BigNum& rightNum) const
{
    BigNum sum;
    int currentSumDigit;

    int carry = 0;

    int leftLength = leftNum.getBigNum().length();
    int rightLength = rightNum.getBigNum().length();

    std::string reversedLeftNum = std::string(leftNum.bigNum.rbegin(), leftNum.bigNum.rend());
    std::string reversedRightNum = std::string(rightNum.bigNum.rbegin(), rightNum.bigNum.rend());
    
    if(leftLength < rightLength)
    {
        for(int i = 0; i < leftLength; ++i)
        {
            currentSumDigit = (reversedLeftNum[i] - '0') + (reversedRightNum[i] - '0') + carry;
            sum.bigNum.push_back(currentSumDigit % 10 + '0');
            carry = currentSumDigit / 10;
        }
        for(int i = leftLength; i < rightLength; ++i)
        {
            currentSumDigit = (reversedRightNum[i] - '0') + carry;
            sum.bigNum.push_back(currentSumDigit % 10 + '0');
            carry = currentSumDigit / 10;
        }
    }   

    else if(leftLength == rightLength)
    {
        for(int i = 0; i < leftLength; ++i)
        {
            currentSumDigit = (reversedLeftNum[i] - '0') + (reversedRightNum[i] - '0') + carry;
            sum.bigNum.push_back(currentSumDigit % 10 + '0');
            carry = currentSumDigit / 10;
        }
    }

    else if(leftLength > rightLength)
    {
        for(int i = 0; i < rightLength; ++i)
        {
            currentSumDigit = (reversedLeftNum[i] - '0') + (reversedRightNum[i] - '0') + carry;
            sum.bigNum.push_back(currentSumDigit % 10 + '0');
            carry = currentSumDigit / 10;
        }
        for(int i = rightLength; i < leftLength; ++i)
        {
            currentSumDigit = (reversedLeftNum[i] - '0') + carry;
            sum.bigNum.push_back(currentSumDigit % 10 + '0');
            carry = currentSumDigit / 10;
        }
    }

    if(carry != 0)
        sum.bigNum.push_back(carry + '0');

    sum.bigNum = std::string(sum.bigNum.rbegin(), sum.bigNum.rend());

    return sum;
}

BigNum BigNum::minus(const BigNum& leftNum, const BigNum& rightNum) const
{
    BigNum difference;

    int differenceCurrentNum;

    int passZero;

    BigNum greater;
    std::string reversedGreater;
    int greaterLength;

    BigNum smaller;
    std::string reversedSmaller;
    int smallerLength;

    if(leftNum > rightNum)
    {
        greater = leftNum;
        reversedGreater = std::string(leftNum.bigNum.rbegin(), leftNum.bigNum.rend());
        greaterLength = leftNum.getBigNum().length();

        smaller = rightNum;
        reversedSmaller = std::string(rightNum.bigNum.rbegin(), rightNum.bigNum.rend());
        smallerLength = rightNum.getBigNum().length();
    }

    else if(leftNum < rightNum)
    {
        greater = rightNum;
        reversedGreater = std::string(rightNum.bigNum.rbegin(), rightNum.bigNum.rend());
        greaterLength = rightNum.getBigNum().length();

        smaller = leftNum;
        reversedSmaller = std::string(leftNum.bigNum.rbegin(), leftNum.bigNum.rend());
        smallerLength = leftNum.getBigNum().length();
    }
   
    else if(leftNum == rightNum)
    {
        difference.setBigNum("0");
        return difference;
    }

    for(int i = 0; i < smallerLength; ++i)
    {
        differenceCurrentNum = (reversedGreater[i] - '0') - (reversedSmaller[i] - '0');

        if(differenceCurrentNum < 0)
        {
            differenceCurrentNum += 10;
            passZero = i + 1;

            while(reversedGreater[passZero] == '0')
                ++passZero;
            --reversedGreater[passZero];
            --passZero;

            while(passZero != i)
            {
                reversedGreater[passZero] += 9;
                --passZero;
            }
        }

        difference.bigNum += std::to_string(differenceCurrentNum);
    }

    if(greaterLength != smallerLength)
        difference.bigNum += reversedGreater.substr(smallerLength);


    difference.bigNum = std::string(difference.bigNum.rbegin(), difference.bigNum.rend());

    if(difference.bigNum[0] == '0')
    {
        passZero = 0;
        for(int i = 0; difference.bigNum[i] == '0'; ++i)
            ++passZero;
        difference.bigNum = difference.bigNum.substr(passZero);
    }

    return difference;
}

BigNum BigNum::multiply(const BigNum& leftNum, const BigNum& rightNum) const
{
    BigNum product("0");

    BigNum CurrentProductNum;
    BigNum reversedCurrentProductNum;
    int currentProductDigit;

    int carry = 0;

    BigNum greater;
    std::string reversedGreater;
    int greaterLength;

    BigNum smaller;
    std::string reversedSmaller;
    int smallerLength;

    if(leftNum >= rightNum)
    {
        greater = leftNum;
        reversedGreater = std::string(leftNum.bigNum.rbegin(), leftNum.bigNum.rend());
        greaterLength = leftNum.getBigNum().length();

        smaller = rightNum;
        reversedSmaller = std::string(rightNum.bigNum.rbegin(), rightNum.bigNum.rend());
        smallerLength = rightNum.getBigNum().length();
    }

    else if(leftNum < rightNum)
    {
        greater = rightNum;
        reversedGreater = std::string(rightNum.bigNum.rbegin(), rightNum.bigNum.rend());
        greaterLength = rightNum.getBigNum().length();

        smaller = leftNum;
        reversedSmaller = std::string(leftNum.bigNum.rbegin(), leftNum.bigNum.rend());
        smallerLength = leftNum.getBigNum().length();
    }

        for(int i = 0; i < smallerLength; ++i)
        {
            for(int k = 0; k < i; ++k)
                reversedCurrentProductNum.bigNum += "0";

            for(int j = 0; j < greaterLength; ++j)
            {
                currentProductDigit = (reversedSmaller[i] - '0') * (reversedGreater[j] - '0') + carry;
                reversedCurrentProductNum.bigNum += std::to_string(currentProductDigit % 10);
                carry = currentProductDigit / 10;
            }

            if(carry != 0)
                reversedCurrentProductNum.bigNum += std::to_string(carry);

            CurrentProductNum.bigNum = std::string(reversedCurrentProductNum.bigNum.rbegin(), 
                                                   reversedCurrentProductNum.bigNum.rend());

            for(int j = 0; j < CurrentProductNum.bigNum.length(); ++j)
            {
                if(CurrentProductNum.bigNum[j] != '0')
                    break;
                if(CurrentProductNum.bigNum[j] == '0')
                    if(j == CurrentProductNum.bigNum.length() - 1)
                        CurrentProductNum.bigNum = "0";
            }

            product += CurrentProductNum;

            CurrentProductNum.bigNum = "";
            reversedCurrentProductNum.bigNum = "";
            carry = 0;
        }
    
    return product;
}

BigNum BigNum::divide(const BigNum& leftNum, const BigNum& rightNum) const
{
    BigNum numerator = leftNum;
    BigNum denominator = rightNum;
    BigNum quotient;

    BigNum currentNumerator;

    int numeratorLength = numerator.bigNum.length();
    int denominatorLength = denominator.bigNum.length();
    bool checkLength = false;

    int numeratorLengthCounter = 0;

    if(denominator.bigNum == "0")
        throw std::invalid_argument("Attempted to divide by zero.");

    if(numerator < denominator)
    {
        quotient.bigNum = "0";
        return quotient;
    }

    currentNumerator.bigNum = numerator.bigNum.substr(0, denominatorLength);
    numeratorLengthCounter += denominatorLength;

    if(currentNumerator < denominator)
    {
        currentNumerator.bigNum = numerator.bigNum.substr(0, denominatorLength + 1);
        ++numeratorLengthCounter;
    }

    for(int i = 0; i <= 10; ++i)
    {
        if(denominator * i > currentNumerator)
        {
            quotient.bigNum += std::to_string(i - 1);
            currentNumerator -= (denominator * (i - 1));
            break;
        }

        if(denominator * i == currentNumerator)
        {
            quotient.bigNum += std::to_string(i);
            currentNumerator.bigNum = "";
            break;
        }
    }

    currentNumerator.bigNum = currentNumerator.bigNum + numerator.bigNum[numeratorLengthCounter];
    ++numeratorLengthCounter;   

    while(numeratorLengthCounter <= numeratorLength)
    {
        for(int i = 0; i <= 10; ++i)
        {
            if(denominator * i > currentNumerator)
            {
                quotient.bigNum += std::to_string(i - 1);
                currentNumerator -= (denominator * (i - 1));
                break;
            }

            if(denominator * i == currentNumerator)
            {
                quotient.bigNum += std::to_string(i);
                currentNumerator.bigNum = "";
                break;
            }
        }   

        currentNumerator.bigNum = currentNumerator.bigNum + numerator.bigNum[numeratorLengthCounter];
        ++numeratorLengthCounter;
    }

    return quotient;
}

BigNum BigNum::modulo(const BigNum& leftNum, const BigNum& rightNum) const
{
    BigNum quotient = leftNum / rightNum;
    BigNum remainder = leftNum - (quotient * rightNum);
    return remainder;
}


std::istream& operator>>(std::istream& input, BigNum& rightNum)
{
    std::string bigNum;
    input >> bigNum;
    rightNum.setBigNum(bigNum);
    return input;
}

std::ostream& operator<<(std::ostream& output, const BigNum& rightNum)
{
    output <<  rightNum.bigNum;    
    return output;
}


BigNum operator+(const BigNum& leftNum, const BigNum& rightNum)
{
    BigNum sum;

    if(leftNum.bigNum >= "0" && rightNum.bigNum >= "0")
        sum = leftNum.plus(leftNum, rightNum);

    else if(leftNum.bigNum <= "0" && rightNum.bigNum <= "0")
    {
        BigNum thisTemp;
        BigNum rightTemp;
        thisTemp.bigNum = leftNum.bigNum.substr(1);
        rightTemp.bigNum = rightNum.bigNum.substr(1);
        sum = leftNum.plus(thisTemp, rightTemp);
        if(sum.bigNum != "0")
        {
            BigNum sumTemp = '-' + sum.bigNum;
            sum = sumTemp;
        }
    }
    
    else if(leftNum.bigNum >= "0" && rightNum.bigNum < "0")
    {
        BigNum rightTemp;
        rightTemp.bigNum = rightNum.bigNum.substr(1);
        sum = leftNum.minus(leftNum, rightTemp);
        if(rightTemp > leftNum && sum.bigNum != "0")
        {
            BigNum sumTemp = '-' + sum.bigNum;
            sum = sumTemp;
        }
    }

    else if(leftNum.bigNum < "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp;
        thisTemp.bigNum = leftNum.bigNum.substr(1);
        sum = leftNum.minus(thisTemp, rightNum);
        if(thisTemp > rightNum && sum.bigNum != "0")
        {
            BigNum sumTemp = '-' + sum.bigNum;
            sum = sumTemp;
        }
    }

    return sum;
}

BigNum operator-(const BigNum& leftNum, const BigNum& rightNum)
{
    BigNum difference;

    if(leftNum.bigNum >= "0" && rightNum.bigNum >= "0")
    {
        difference = leftNum.minus(leftNum, rightNum);
        if(rightNum > leftNum && difference.bigNum != "0")
        {
            BigNum differenceTemp = '-' + difference.bigNum;
            difference = differenceTemp;
        }
    }

    else if(leftNum.bigNum < "0" && rightNum.bigNum < "0")
    {
        BigNum thisTemp = leftNum.bigNum.substr(1);
        BigNum rightTemp = rightNum.bigNum.substr(1);
        difference = leftNum.minus(thisTemp, rightTemp);
        if(thisTemp > rightTemp && difference.bigNum != "0")
        {
            BigNum differenceTemp = '-' + difference.bigNum;
            difference = differenceTemp;
        }
    }
    
    else if(leftNum.bigNum >= "0" && rightNum.bigNum < "0")
    {
        BigNum rightTemp;
        rightTemp.bigNum = rightNum.bigNum.substr(1);
        difference = leftNum.plus(leftNum, rightTemp);
    }

    else if(leftNum.bigNum < "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp;
        thisTemp.bigNum = leftNum.bigNum.substr(1);
        difference = leftNum.plus(thisTemp, rightNum);
        if(difference.bigNum != "0")
        {
            BigNum differenceTemp = '-' + difference.bigNum;
            difference = differenceTemp;
        }
    }

    return difference;  
}

BigNum operator*(const BigNum& leftNum, const BigNum& rightNum)
{
    BigNum product;

    if(leftNum.bigNum >= "0" && rightNum.bigNum >= "0")
        product = leftNum.multiply(leftNum, rightNum);

    if(leftNum.bigNum < "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp = leftNum.bigNum.substr(1);
        product = leftNum.multiply(thisTemp, rightNum);
        if(product.bigNum != "0")
        {
            BigNum productTemp = '-' + product.bigNum;
            product = productTemp;
        }
    }

    if(leftNum.bigNum >= "0" && rightNum.bigNum < "0")
    {
        BigNum rightTemp = rightNum.bigNum.substr(1);
        product = leftNum.multiply(leftNum, rightTemp);
        if(product.bigNum != "0")
        {
            BigNum productTemp = '-' + product.bigNum;
            product = productTemp;
        }
    }

    if(leftNum.bigNum < "0" && rightNum.bigNum < "0")
    {
        BigNum thisTemp = leftNum.bigNum.substr(1);
        BigNum rightTemp = rightNum.bigNum.substr(1);
        product = leftNum.multiply(thisTemp, rightTemp);
    }
    
    return product;
}

BigNum operator/(const BigNum& leftNum, const BigNum& rightNum)
{
    BigNum quotient;

    if(leftNum.bigNum >= "0" && rightNum.bigNum >= "0")
        quotient = leftNum.divide(leftNum, rightNum);

    if(leftNum.bigNum < "0" && rightNum.bigNum >= "0")
    {
        BigNum thisTemp = leftNum.bigNum.substr(1);
        quotient = leftNum.divide(thisTemp, rightNum);
        if(quotient.bigNum != "0")
        {
            BigNum quotientTemp = '-' + quotient.bigNum;
            quotient = quotientTemp;
        }
    }

    if(leftNum.bigNum >= "0" && rightNum.bigNum < "0")
    {
        BigNum rightTemp = rightNum.bigNum.substr(1);
        quotient = leftNum.divide(leftNum, rightTemp);
        if(quotient.bigNum != "0")
        {
            BigNum quotientTemp = '-' + quotient.bigNum;
            quotient = quotientTemp;
        }
    }

    if(leftNum.bigNum < "0" && rightNum.bigNum < "0")
    {
        BigNum thisTemp = leftNum.bigNum.substr(1);
        BigNum rightTemp = rightNum.bigNum.substr(1);
        quotient = leftNum.divide(thisTemp, rightTemp);
    }
    
    return quotient;
}

BigNum operator%(const BigNum& leftNum, const BigNum& rightNum)
{
    BigNum remainder = leftNum.modulo(leftNum, rightNum);
    return remainder;
}


bool operator<(const BigNum& leftNum, const BigNum& rightNum)
{
    if(leftNum.bigNum == rightNum.bigNum)
        return false;

    if(leftNum.bigNum > "0" && rightNum.bigNum < "0")
        return false;

    if(leftNum.bigNum < "0" && rightNum.bigNum > "0")
        return true;

    if(leftNum.bigNum > "0" && rightNum.bigNum > "0")
    {
        if(leftNum.bigNum.length() > rightNum.bigNum.length())
            return false;
        if(leftNum.bigNum.length() < rightNum.bigNum.length())
            return true;
        else
            for(int i = 0; i < leftNum.bigNum.length(); ++i)
                if(leftNum.bigNum > rightNum.bigNum)
                    return false;
        return true;
    }

    if(leftNum.bigNum < "0" && rightNum.bigNum < "0")
    {
        if(leftNum.bigNum.length() > rightNum.bigNum.length())
            return true;
        if(leftNum.bigNum.length() < rightNum.bigNum.length())
            return false;
        else
            for(int i = 0; i < leftNum.bigNum.length(); ++i)
                if(leftNum.bigNum > rightNum.bigNum)
                    return true;
        return false;
    }

    if(leftNum.bigNum == "0")
    {
        if(rightNum.bigNum[0] == '-')
            return false;
        else
            return true;
    }

    if(rightNum.bigNum == "0")
    {
        if(leftNum.bigNum[0] == '-')
            return true;
        else
            return false;
    }

}

bool operator<=(const BigNum& leftNum, const BigNum& rightNum)
{
    return !(leftNum > rightNum);
}

bool operator>(const BigNum& leftNum, const BigNum& rightNum)
{
    if(leftNum.bigNum == rightNum.bigNum)
        return false;

    if(leftNum.bigNum > "0" && rightNum.bigNum < "0")
        return true;

    if(leftNum.bigNum < "0" && rightNum.bigNum > "0")
        return false;

    if(leftNum.bigNum > "0" && rightNum.bigNum > "0")
    {
        if(leftNum.bigNum.length() > rightNum.bigNum.length())
            return true;
        if(leftNum.bigNum.length() < rightNum.bigNum.length())
            return false;
        else
            for(int i = 0; i < leftNum.bigNum.length(); ++i)
                if(leftNum.bigNum > rightNum.bigNum)
                    return true;
        return false;
    }

    if(leftNum.bigNum < "0" && rightNum.bigNum < "0")
    {
        if(leftNum.bigNum.length() > rightNum.bigNum.length())
            return false;
        if(leftNum.bigNum.length() < rightNum.bigNum.length())
            return true;
        else
            for(int i = 0; i < leftNum.bigNum.length(); ++i)
                if(leftNum.bigNum > rightNum.bigNum)
                    return false;
        return true;
    }

    if(leftNum.bigNum == "0")
    {
        if(rightNum.bigNum[0] == '-')
            return true;
        else
            return false;
    }

    if(rightNum.bigNum == "0")
    {
        if(leftNum.bigNum[0] == '-')
            return false;
        else
            return true;
    }
}

bool operator>=(const BigNum& leftNum, const BigNum& rightNum)
{
    return !(leftNum < rightNum);
}

bool operator==(const BigNum& leftNum, const BigNum& rightNum)
{
    return leftNum.bigNum == rightNum.bigNum;
}

bool operator!=(const BigNum& leftNum, const BigNum& rightNum)
{
    return leftNum.bigNum != rightNum.bigNum;
}


int& operator+=(int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum + static_cast<int>(rightNum);
    return leftNum;
}

int& operator-=(int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum - static_cast<int>(rightNum);
    return leftNum;
}

int& operator*=(int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum * static_cast<int>(rightNum);
    return leftNum;
}

int& operator/=(int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum / static_cast<int>(rightNum);
    return leftNum;
}

int& operator%=(int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum % static_cast<int>(rightNum);
    return leftNum;
}


long int& operator+=(long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum + static_cast<long int>(rightNum);
    return leftNum;
}

long int& operator-=(long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum - static_cast<long int>(rightNum);
    return leftNum;
}

long int& operator*=(long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum * static_cast<long int>(rightNum);
    return leftNum;
}

long int& operator/=(long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum / static_cast<long int>(rightNum);
    return leftNum;
}

long int& operator%=(long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum % static_cast<long int>(rightNum);
    return leftNum;
}


long long int& operator+=(long long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum + static_cast<long long int>(rightNum);
    return leftNum;
}

long long int& operator-=(long long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum - static_cast<long long int>(rightNum);
    return leftNum;
}

long long int& operator*=(long long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum * static_cast<long long int>(rightNum);
    return leftNum;
}

long long int& operator/=(long long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum / static_cast<long long int>(rightNum);
    return leftNum;
}

long long int& operator%=(long long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum % static_cast<long long int>(rightNum);
    return leftNum;
}


unsigned int& operator+=(unsigned int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum + static_cast<unsigned int>(rightNum);
    return leftNum;
}

unsigned int& operator-=(unsigned int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum - static_cast<unsigned int>(rightNum);
    return leftNum;
}

unsigned int& operator*=(unsigned int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum * static_cast<unsigned int>(rightNum);
    return leftNum;
}

unsigned int& operator/=(unsigned int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum / static_cast<unsigned int>(rightNum);
    return leftNum;
}

unsigned int& operator%=(unsigned int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum % static_cast<unsigned int>(rightNum);
    return leftNum;
}


unsigned long int& operator+=(unsigned long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum + static_cast<unsigned long int>(rightNum);
    return leftNum;
}

unsigned long int& operator-=(unsigned long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum - static_cast<unsigned long int>(rightNum);
    return leftNum;
}

unsigned long int& operator*=(unsigned long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum * static_cast<unsigned long int>(rightNum);
    return leftNum;
}

unsigned long int& operator/=(unsigned long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum / static_cast<unsigned long int>(rightNum);
    return leftNum;
}

unsigned long int& operator%=(unsigned long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum % static_cast<unsigned long int>(rightNum);
    return leftNum;
}


unsigned long long int& operator+=(unsigned long long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum + static_cast<unsigned long long int>(rightNum);
    return leftNum;
}

unsigned long long int& operator-=(unsigned long long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum - static_cast<unsigned long long int>(rightNum);
    return leftNum;
}

unsigned long long int& operator*=(unsigned long long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum * static_cast<unsigned long long int>(rightNum);
    return leftNum;
}

unsigned long long int& operator/=(unsigned long long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum / static_cast<unsigned long long int>(rightNum);
    return leftNum;
}

unsigned long long int& operator%=(unsigned long long int& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum % static_cast<long long int>(rightNum);
    return leftNum;
}


double& operator+=(double& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum + static_cast<long int>(rightNum);
    return leftNum;
}

double& operator-=(double& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum - static_cast<long int>(rightNum);
    return leftNum;
}

double& operator*=(double& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum * static_cast<long int>(rightNum);
    return leftNum;
}

double& operator/=(double& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum / static_cast<long int>(rightNum);
    return leftNum;
}


long double& operator+=(long double& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum + static_cast<long long int>(rightNum);
    return leftNum;
}

long double& operator-=(long double& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum - static_cast<long long int>(rightNum);
    return leftNum;
}

long double& operator*=(long double& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum * static_cast<long long int>(rightNum);
    return leftNum;
}

long double& operator/=(long double& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum / static_cast<long long int>(rightNum);
    return leftNum;
}


float& operator+=(float& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum + static_cast<long int>(rightNum);
    return leftNum;
}

float& operator-=(float& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum - static_cast<long int>(rightNum);
    return leftNum;
}

float& operator*=(float& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum * static_cast<long int>(rightNum);
    return leftNum;
}

float& operator/=(float& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum / static_cast<long int>(rightNum);
    return leftNum;
}


char& operator+=(char& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum + static_cast<int>(rightNum);
    return leftNum;
}

char& operator-=(char& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum - static_cast<int>(rightNum);
    return leftNum;
}

char& operator*=(char& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum * static_cast<int>(rightNum);
    return leftNum;
}

char& operator/=(char& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum / static_cast<int>(rightNum);
    return leftNum;
}

char& operator%=(char& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum % static_cast<int>(rightNum);
    return leftNum;
}


bool& operator+=(bool& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum + static_cast<long long int>(rightNum);
    return leftNum;
}

bool& operator-=(bool& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum - static_cast<long long int>(rightNum);
    return leftNum;
}

bool& operator*=(bool& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum * static_cast<long long int>(rightNum);
    return leftNum;
}

bool& operator/=(bool& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum / static_cast<long long int>(rightNum);
    return leftNum;
}

bool& operator%=(bool& leftNum, const BigNum& rightNum)
{
    leftNum = leftNum % static_cast<long long int>(rightNum);
    return leftNum;
}
