    #include <iostream>
    #include <cstring>

    int main() {
        const char *inputString = "Hello World"; // The input string

        std::cout << "Original string: " << inputString << std::endl;

        int length = strlen(inputString);

        char result[length + 1]; 

        for (int i = 0; i < length; ++i) {
            result[i] = inputString[i] ^ 127; 
        }

        result[length] = '\0'; 

        std::cout << "XORed string: " << result << std::endl;

        for (int i = 0; i < length; ++i) {
            result[i] = result[i] ^ 127; 
        }
     std::cout << "XORed string: " << result << std::endl;
        return 0;
    }
