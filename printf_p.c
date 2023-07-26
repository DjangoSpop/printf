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
    return 0;
}

