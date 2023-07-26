#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    char ch;

    while (*format) {
        if (*format == '%') {
            format++; // Move to the next character after '%'

            // Flags
            int flag_plus = 0;
            int flag_space = 0;
            int flag_hash = 0;
            
            // Check for flags
            while (*format == '+' || *format == ' ' || *format == '#') {
                if (*format == '+') {
                    flag_plus = 1;
                } else if (*format == ' ') {
                    flag_space = 1;
                } else if (*format == '#') {
                    flag_hash = 1;
                }
                format++;
            }

            switch (*format) {
                case 'c':
                    ch = va_arg(args, int);
                    putchar(ch);
                    count++;
                    break;
                case 's': {
                    char *str = va_arg(args, char *);
                    while (*str) {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case 'p': {
                    void *ptr = va_arg(args, void *);
                    printf("%p", ptr);
                    count += sizeof(void *);
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    // Handle unsupported format specifiers (optional)
                    putchar(*format);
                    count++;
            }
            
            // Apply flags for non-custom conversion specifiers
            if (flag_plus && (*format == 'd' || *format == 'i')) {
                putchar('+');
                count++;
            }
            
            if (flag_space && (*format == 'd' || *format == 'i')) {
                putchar(' ');
                count++;
            }
            
            if (flag_hash && *format == 'x') {
                putchar('0');
                putchar('x');
                count += 2;
            } else if (flag_hash && *format == 'X') {
                putchar('0');
                putchar('X');
                count += 2;
            } else if (flag_hash && *format == 'o') {
                putchar('0');
                count++;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

int main() {
    int value = 42;
    int *ptr = &value;
    _printf("Address of value: %p\n", ptr);
    _printf("Integer: %+d, %+i\n", 10, -20);
    _printf("Hexadecimal: %#x, %#X\n", 255, 255);
    _printf("Octal: %#o\n", 42);
    return 0;
}
