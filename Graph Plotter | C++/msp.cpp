#include "msp.h"

msp::msp(string infix) {
	input = infix;
}
int msp::prec(char c) {
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
int msp::endPosOfTrigFuncInfix(string s, int pos) {
    int c = pos;

	while (s[c] != ')') {
		c++; // c++; funny! :)
	}
	return c;
}
string msp::trigFunctionValueInString(int posOfLbracket, string s, string trigFuncName) {
	string trigInfix = "";
	string trigPostfix = "";
	double valueOfTrigAngle;
	double valueOfTrigFunc;
	string strValOfTrigFunc;
	ostringstream str;
	int c;
	std::stack<char> st;

	if (s[posOfLbracket] == '(') {
        c = posOfLbracket + 1;
        st.push('N'); // NULL
        st.push('(');

        while(st.top() != 'N'){
            if(s[c] == '('){
                st.push('(');
                trigInfix += s[c];
                c++; // c++; funny! :)
            }
            else if(s[c] == ')'){
                st.pop();
                if(st.top() == 'N'){
                    continue;
                }
                else{
                    trigInfix += s[c];
                    c++;
                }
            }
            else{
                trigInfix += s[c];
                c++;
            }
        }
		trigPostfix = infixToPostfix(trigInfix);
		valueOfTrigAngle = evaluatePostfix(trigPostfix);
		if (trigFuncName == "sin") {
			valueOfTrigFunc = sin(valueOfTrigAngle);
		}
		else if (trigFuncName == "cos") {
			valueOfTrigFunc = cos(valueOfTrigAngle);
		}
		else if (trigFuncName == "tan") {
			valueOfTrigFunc = tan(valueOfTrigAngle);
		}
		else if (trigFuncName == "csc") {
			valueOfTrigFunc = 1.0 / sin(valueOfTrigAngle);
		}
		else if (trigFuncName == "sec") {
			valueOfTrigFunc = 1.0 / cos(valueOfTrigAngle);
		}
		else if (trigFuncName == "cot") {
			valueOfTrigFunc = 1.0 / tan(valueOfTrigAngle);
		}
		// hyperbolic trig
		else if (trigFuncName == "sinh") {
			valueOfTrigFunc = sinh(valueOfTrigAngle);
		}
		else if (trigFuncName == "cosh") {
			valueOfTrigFunc = cosh(valueOfTrigAngle);
		}
		else if (trigFuncName == "tanh") {
			valueOfTrigFunc = tanh(valueOfTrigAngle);
		}
		else if (trigFuncName == "csch") {
			valueOfTrigFunc = 1.0 / sinh(valueOfTrigAngle);
		}
		else if (trigFuncName == "sech") {
			valueOfTrigFunc = 1.0 / cosh(valueOfTrigAngle);
		}
		else if (trigFuncName == "coth") {
			valueOfTrigFunc = 1.0 / tanh(valueOfTrigAngle);
		}
		else if (trigFuncName == "asin") {
			valueOfTrigFunc = asin(valueOfTrigAngle);
		}
		else if (trigFuncName == "acos") {
			valueOfTrigFunc = acos(valueOfTrigAngle);
		}
		else if (trigFuncName == "atan") {
			valueOfTrigFunc = atan(valueOfTrigAngle);
		}
		else if (trigFuncName == "acsc") {
			valueOfTrigFunc = 1.0 / asin(valueOfTrigAngle);
		}
		else if (trigFuncName == "asec") {
			valueOfTrigFunc = 1.0 / acos(valueOfTrigAngle);
		}
		else if (trigFuncName == "acot") {
			valueOfTrigFunc = 1.0 / atan(valueOfTrigAngle);
		}
		else
			return "errorInTrigName";
		str << valueOfTrigFunc;
        strValOfTrigFunc = str.str();
		if (strValOfTrigFunc[0] == '-') {
			string strTempTrigFuncVal;
			strTempTrigFuncVal = '~';
			for (int k = 1; k<strValOfTrigFunc.length(); k++) {
				strTempTrigFuncVal += strValOfTrigFunc[k];
			}
			strValOfTrigFunc = strTempTrigFuncVal;
		}
	}
	else
		return "errorNoLeftBreacket";
	return strValOfTrigFunc;
}
string msp::infixToPostfix(string s) {
	std::stack<char> st;
	st.push('N'); // null
	int len = s.length();
    string ns;
    int c;
	for (int i = 0; i<len; i++) {
		if (s[i] == 's' || s[i] == 'c' || s[i] == 't' || s[i] == 'a') {
			string trigFuncName;
            if (s[i] == 's' && s[i + 1] == 'i' && s[i + 2] == 'n' &&  s[i + 3] != 'h') {
                trigFuncName = "sin";
                ns += trigFunctionValueInString(i + 3, s, trigFuncName);
                i = endPosOfTrigFuncInfix(s, i + 4);
			}
			else if (s[i] == 'c' && s[i + 1] == 's' && s[i + 2] == 'c' &&  s[i + 3] != 'h') {
				trigFuncName = "csc";
				ns += trigFunctionValueInString(i + 3, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 4);
			}
			else if (s[i] == 'c' && s[i + 1] == 'o' && s[i + 2] == 's' &&  s[i + 3] != 'h') {
				trigFuncName = "cos";
				ns += trigFunctionValueInString(i + 3, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 4);
            }
			else if (s[i] == 's' && s[i + 1] == 'e' && s[i + 2] == 'c' &&  s[i + 3] != 'h') {
				trigFuncName = "sec";
				ns += trigFunctionValueInString(i + 3, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 4);
            }
			else if (s[i] == 't' && s[i + 1] == 'a' && s[i + 2] == 'n' &&  s[i + 3] != 'h') {
				trigFuncName = "tan";
				ns += trigFunctionValueInString(i + 3, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 4);
            }
			else if (s[i] == 'c' && s[i + 1] == 'o' && s[i + 2] == 't' &&  s[i + 3] != 'h') {
				trigFuncName = "cot";
				ns += trigFunctionValueInString(i + 3, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 4);
            }
			else if (s[i] == 's' && s[i + 1] == 'i' && s[i + 2] == 'n' && s[i + 3] == 'h') {
				trigFuncName = "sinh";
				ns += trigFunctionValueInString(i + 4, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 5);
            }
			else if (s[i] == 'c' && s[i + 1] == 's' && s[i + 2] == 'c' && s[i + 3] == 'h') {
				trigFuncName = "csch";
				ns += trigFunctionValueInString(i + 4, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 5);
            }
			else if (s[i] == 'c' && s[i + 1] == 'o' && s[i + 2] == 's' && s[i + 3] == 'h') {
				trigFuncName = "cosh";
				ns += trigFunctionValueInString(i + 4, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 5);
            }
			else if (s[i] == 's' && s[i + 1] == 'e' && s[i + 2] == 'c' && s[i + 3] == 'h') {
				trigFuncName = "sech";
				ns += trigFunctionValueInString(i + 4, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 5);
            }
			else if (s[i] == 't' && s[i + 1] == 'a' && s[i + 2] == 'n' && s[i + 3] == 'h') {
				trigFuncName = "tanh";
				ns += trigFunctionValueInString(i + 4, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 5);
            }
			else if (s[i] == 'c' && s[i + 1] == 'o' && s[i + 2] == 't' && s[i + 3] == 'h') {
				trigFuncName = "coth";
				ns += trigFunctionValueInString(i + 4, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 5);
            }
			else if (s[i] == 'a' && s[i + 1] == 's' && s[i + 2] == 'i' && s[i + 3] == 'n') {
				trigFuncName = "asin";
				ns += trigFunctionValueInString(i + 4, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 5);
            }
			else if (s[i] == 'a' && s[i + 1] == 'c' && s[i + 2] == 's' && s[i + 3] == 'c') {
				trigFuncName = "acsc";
				ns += trigFunctionValueInString(i + 4, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 5);
            }
			else if (s[i] == 'a' && s[i + 1] == 'c' && s[i + 2] == 'o' && s[i + 3] == 's') {
				trigFuncName = "acos";
				ns += trigFunctionValueInString(i + 4, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 5);
            }
			else if (s[i] == 'a' && s[i + 1] == 's' && s[i + 2] == 'e' && s[i + 3] == 'c') {
				trigFuncName = "asec";
				ns += trigFunctionValueInString(i + 4, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 5);
            }
			else if (s[i] == 'a' && s[i + 1] == 't' && s[i + 2] == 'a' && s[i + 3] == 'n') {
				trigFuncName = "atan";
				ns += trigFunctionValueInString(i + 4, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 5);
            }
			else if (s[i] == 'a' && s[i + 1] == 'c' && s[i + 2] == 'o' && s[i + 3] == 't') {
				trigFuncName = "acot";
				ns += trigFunctionValueInString(i + 4, s, trigFuncName);
				i = endPosOfTrigFuncInfix(s, i + 5);
			}
			ns += '_';
		}
        else if (s[i] == '~') {
			ns += '~';
			i++;
			if (s[i] >= 48 && s[i] <= 57) {
				c = i;
				ns += s[c];
				c++;
				while (isdigit(s[c]) || s[c] == '.') {
					ns += s[c];
					c++;
				}
				ns += '_';
				i = c - 1;
			}
			else
				return "error";
		}
		else if (s[i] >= 48 && s[i] <= 57) {
			c = i;
			ns += s[c];
			c++;
			while (isdigit(s[c]) || s[c] == '.') {
				ns += s[c];
				c++;
			}
			ns += '_';
			i = c - 1;
        }
		else if (s[i] == '(')
            st.push('(');
		else if (s[i] == ')') {
			while (st.top() != 'N' && st.top() != '(') {
				char c = st.top();
				st.pop();
				ns += c;
				ns += '_';
			}
			if (st.top() == '(') {
				st.pop();
			}
		}
		else {
			while (st.top() != 'N' && prec(s[i]) <= prec(st.top())) {
				char c = st.top();
				st.pop();
				ns += c;
				ns += '_';
			}
			st.push(s[i]);
		}
    }
	while (st.top() != 'N') {
		char c = st.top();
		st.pop();
		ns += c;
		ns += '_';
	}

	return ns;
}
double msp::evaluatePostfix(string s) {
	std::stack<double> st;
	int len = s.length();
	string operandStr = "";
    int flag = 0;
	for (int i = 0; i<len; ++i) {
		if (s[i] == '_') {
		}
		else if (s[i] == '~') {
			i++;
			if (isdigit(s[i])) {
				operandStr = "";
				int flag = 0;
				while (s[i] != '_') {
					if (s[i] == '.')
						flag = 1;
					operandStr += s[i];
					i++;
				}
				if (flag == 0) {
                    int tempOperandNegative = -abs(multiCharDigitToNumber(1, operandStr));
					st.push(tempOperandNegative);
				}
				else {
                    double tempOperandNegative = -abs(multiCharDigitToNumber(0.0, operandStr));
					st.push(tempOperandNegative);
				}
			}
		}
		else if (isdigit(s[i])) {
			operandStr = "";
			int flag = 0;
			while (s[i] != '_') {
				if (s[i] == '.')
					flag = 1;
				operandStr += s[i];
				i++;
			}
			if (flag == 0) {
				st.push(multiCharDigitToNumber(1, operandStr));
			}
			else {
				st.push(multiCharDigitToNumber(0.0, operandStr));
			}
		}
		else {
			double val1 = st.top(); st.pop();
			double val2 = st.top(); st.pop();
			switch (s[i]) {
			case '+': st.push(val2 + val1); break;
			case '-': st.push(val2 - val1); break;
			case '*': st.push(val2 * val1); break;
			case '/': st.push(val2 / val1); break;
			case '^': st.push(pow(val2, val1)); break;
			}
		}
	}

	return st.top();
}
template <class T>
T msp::multiCharDigitToNumber(T intOrDec, string inputCharDigits) {
	int len = inputCharDigits.length();
	T mainValue;

	T first, second;

    int i = 0;
	int flag = 0, decimalCounter = 1;
	if (intOrDec == 1) {
		if (len == 1) {
			first = inputCharDigits[i] - '0';
		}
		else {
            while (i < len) {
				if (flag == 0) {
					first = inputCharDigits[i] - '0';
					second = inputCharDigits[i + 1] - '0';

					first = first * 10 + second;

                    i += 2;

                    flag = 1;
				}
				else {
					second = inputCharDigits[i] - '0';
					first = first * 10 + second;
					i++;
				}
			}
		}
	}
	else {
        T leftValue, rightValue;
		if (inputCharDigits[i + 1] == '.') {
			first = inputCharDigits[i] - '0';
			i++;
        }
		else {
			while (inputCharDigits[i] != '.') {
				if (flag == 0) {
					first = inputCharDigits[i] - '0';
					second = inputCharDigits[i + 1] - '0';

					first = first * 10 + second;

                    i += 2;

                    flag = 1;
				}
				else {
					second = inputCharDigits[i] - '0';
					first = first * 10 + second;
					i++;
				}
			}
		}
		leftValue = first;
		i++;
        flag = 0;
        if (i + 1 == len) {
			first = inputCharDigits[i] - '0';
			decimalCounter *= 10;
        }
		else {
            while (i<len) {
				if (flag == 0) {
					first = inputCharDigits[i] - '0';
					second = inputCharDigits[i + 1] - '0';

					first = first * 10 + second;

                    i += 2;

                    flag = 1;
					decimalCounter *= 10;
					decimalCounter *= 10;
				}
				else {
					second = inputCharDigits[i] - '0';
					first = first * 10 + second;
					i++;

					decimalCounter *= 10;
				}
			}
		}

		rightValue = first;
		rightValue = rightValue / decimalCounter;
		first = leftValue + rightValue;
	}
	mainValue = first;

	return mainValue;
}
double msp::returnYvalue(double xVal) {
	int i = 0;
	std::ostringstream ss;
	ss << xVal;

	string strX = ss.str();
	string inputInfix;
	string postfixStr;

	// use to handle -ve sign in strX
	if (strX[0] == '-') {
		string temp = "~";
		i = 1;
		while (i < strX.length()) {
			temp += strX[i];
			i++;
		}
		strX = temp;
	}
    i = 0;
    while (i < input.length()) {
        if (input[i] == 'x') {
			if (isdigit(input[i - 1]) && isdigit(input[i + 1]) == false) {
				inputInfix += '*';
				inputInfix += strX;
            }
			else if (isdigit(input[i + 1]) && isdigit(input[i - 1]) == false) {
				inputInfix += strX;
				inputInfix += '*';
            }
			else if (isdigit(input[i - 1]) && isdigit(input[i + 1])) {
				inputInfix += '*';
				inputInfix += strX;
				inputInfix += '*';
            }
			else {
				inputInfix += strX;
			}
		}
		else {
			inputInfix += input[i];
		}
		i++;
	}

	postfixStr = infixToPostfix(inputInfix);

	return evaluatePostfix(postfixStr);
}
