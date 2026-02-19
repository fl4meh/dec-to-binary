#include <iostream>
#include <vector>
#include <windows.h>

void clearScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD written;
    COORD topLeft = {0, 0};

    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &written);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, consoleSize, topLeft, &written);
    SetConsoleCursorPosition(hConsole, topLeft);
}

class Stack{
    std::vector<char> arr;
    public:
    
    void push(int var){
        arr.push_back(var);
    }
    int pop_value(){
        int c = arr.back();
        arr.pop_back();
        return c; 
    }
    bool is_empty(){
        return arr.empty();
    }
};

void dec_to_binary(int decimal){
    int result;
    Stack stack;
    
    while (decimal > 0){
        result = decimal % 2;
        stack.push(result);
        decimal /= 2;
    }

    while (!stack.is_empty()){
        std::cout << stack.pop_value();
    }

}

void dec_to_octal(int decimal){
    int result;
    Stack stack;

    while (decimal > 0){
        result = decimal % 8;
        stack.push(result);
        decimal /= 8;
    }
    while (!stack.is_empty()){
        std::cout << stack.pop_value();
    }
}



int main(){
    clearScreen();
    std::cout << "Lousy Decimal to Binary Calculator" << std::endl;
    std::cout << "Notes:" << std::endl << "It is recommended to use a terminal when running this file. " << std::endl;
    std::cout << "Follow the input instructions so that the program will not break." << std::endl;
    std::cout << "If you are using a terminal, Ctrl + C to TERMINATE." << std::endl;
    std::cout << "Also, be careful with inputs as I did not implement any error handling" << std::endl;
    std::cout << "Lastly, this program is heavily dependent on WINDOWS" << std::endl;
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    while (true){
        int c;
        std::cout << "1. Decimal to Binary" << std::endl << "2. Addition" << std::endl;
        std::cout << "3. Subtraction" << std:: endl << "4. Multiplication" << std::endl;
        std::cout << "5. Division" << std::endl << "6. Octal Convert" << std::endl;
        std::cout << std::endl;
        std::cout << "Choice: ";
        std::cin >> c;
        std::cout << "---------------------------------------------------------------------------------" << std::endl;
        switch(c){
            case 1: {
            int dec = 0;
            std::cout << "Input format: A " << std::endl;
            std::cout << "Decimal: ";
            std::cin >> dec;
            std::cout << "Result: "; dec_to_binary(dec);
            std::cout << std::endl;
            std::cout << "---------------------------------------------------------------------------------" << std::endl;            
            break;
            }
            case 2: {
            int num1, num2, result;
            std::cout << "Input format: A B" << std::endl;
            std::cout << "Two nums: ";
            std::cin >> num1 >> num2;
            result = num1 + num2;
            std::cout << "First: "; dec_to_binary(num1); std::cout << std::endl;
            std::cout << "Second: "; dec_to_binary(num2); std::cout << std::endl;
            std::cout << "Result: "; dec_to_binary(result); std::cout <<  std::endl;
            std::cout << "---------------------------------------------------------------------------------" << std::endl;
            break;
            }
            case 3: {
            int num1, num2, result;
            std::cout << "Input format: A B, where A is greater than B" << std::endl;
            std::cout << "Two nums: ";
            std::cin >> num1 >> num2;
            result = num1 - num2;
            std::cout << "First: "; dec_to_binary(num1); std::cout << std::endl;
            std::cout << "Second: "; dec_to_binary(num2); std::cout << std::endl;
            std::cout << "Result: "; dec_to_binary(result); std::cout <<  std::endl; 
            std::cout << "---------------------------------------------------------------------------------" << std::endl;
            break;
            }
            case 4: {
            int num1, num2, result;
            std::cout << "Input format: A B" << std::endl;
            std::cout << "Two nums: ";
            std::cin >> num1 >> num2;
            result = num1 * num2;
            std::cout << "First: "; dec_to_binary(num1); std::cout << std::endl;
            std::cout << "Second: "; dec_to_binary(num2); std::cout << std::endl;
            std::cout << "Result: "; dec_to_binary(result); std::cout <<  std::endl;
            std::cout << "---------------------------------------------------------------------------------" << std::endl;
            break;
            }
            case 5: {
            int num1, num2, result;
            std::cout << "Input format: A B, where B is not 0" << std::endl;
            std::cout << "Two nums: ";
            std::cin >> num1 >> num2;
            result = num1 / num2;
            std::cout << "First: "; dec_to_binary(num1); std::cout << std::endl;
            std::cout << "Second: "; dec_to_binary(num2); std::cout << std::endl;
            std::cout << "Result: "; dec_to_binary(result); std::cout <<  std::endl;
            std::cout << "---------------------------------------------------------------------------------" << std::endl;
            break;
            }
            case 6: {
            int dec;
            std::cout << "Input format: A" << std::endl;
            std::cout << "Decimal: ";
            std::cin >> dec;
            std::cout << "Result: "; dec_to_octal(dec);
            std::cout << std::endl;
            std::cout << "---------------------------------------------------------------------------------" << std::endl;            
            break;
            }
        }
    }
    return 0;
}