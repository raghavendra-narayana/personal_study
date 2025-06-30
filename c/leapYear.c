#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// 1. Print the bit pattern of a uint32_t number
void print_bit_pattern(uint32_t n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

// 2. Set xth bit in number n
#define SET_BIT(n, bit) (n |= (1U << bit))

// 3. Unset xth bit in number n
#define UNSET_BIT(n, bit) (n &= ~(1U << bit))

// 4. Check if xth bit is set in number n
#define IS_BIT_SET(n, bit) ((n & (1U << bit)) != 0)

// 5. Toggle xth bit in number n
#define TOGGLE_BIT(n, bit) (n ^= (1U << bit))

// 6. Compute the complement of number n
#define COMPLEMENT(n) (~n)

// 7. Count the number of bits set in a uint32_t number
uint8_t count_bit_set(uint32_t n) {
    uint8_t count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// 8. Rotate the bit pattern of number n by k units towards right
uint32_t rotate_right(uint32_t n, int k) {
    k %= 32;  // To handle k > 32 cases
    return (n >> k) | (n << (32 - k));
}

// 9. Apply mask on IP Address and print the bit pattern of the result
void apply_mask_and_print(uint32_t ip, uint8_t mask) {
    uint32_t masked_ip = ip & (~0U << (32 - mask));
    print_bit_pattern(masked_ip);
}

// 10. Print the integer formed by bits in [p, q] interval
uint32_t extract_bits(uint32_t n, int p, int q) {
    uint32_t mask = ((1U << (q - p + 1)) - 1) << p;
    return (n & mask) >> p;
}

// 11. Test if n is a power of two
bool isPowerOfTwo(uint32_t n) {
    if(n == 0)
        return 0;
 /*   printf("n %X n-1 %X (n & (n - 1)) %X ((n & (n - 1)) == 0) %X\n", n,  (n - 1), (n & (n - 1)), ((n & (n - 1)) == 0));
    return n && ((n & (n - 1)) == 0);
*/

    /* First x in the below expression is for the case when
     * x is 0 */
    printf("n %X n-1 %X (n & (n - 1)) %X (!(n & (n - 1))) %X\n", n,  (n - 1), (n & (n - 1)), (!(n & (n - 1))));
    return (!(n & (n - 1)));    
}

int test_bitwise_operators() {
    uint32_t n = 40;
    // 1. Print bit pattern
    print_bit_pattern(n);
    // 2. Set bit
    SET_BIT(n, 3);
    print_bit_pattern(n);
    // 3. Unset bit
    UNSET_BIT(n, 4);
    print_bit_pattern(n);
    // 4. Check if bit is set
    printf("%d\n", IS_BIT_SET(n, 3));
    // 5. Toggle bit
    TOGGLE_BIT(n, 2);
    print_bit_pattern(n);
    // 6. Complement of n
    uint32_t complemented = COMPLEMENT(n);
    print_bit_pattern(complemented);
    // 7. Count bits set
    printf("%d\n", count_bit_set(n));
    // 8. Rotate right
    uint32_t rotated = rotate_right(n, 4);
    print_bit_pattern(rotated);
    // 9. Apply mask and print
    apply_mask_and_print(0x14010102, 24);
    // 10. Extract bits
    printf("%u\n", extract_bits(n, 1, 4));
    // 11. Test power of two
    for(int loop=0; loop<300;loop++){
        printf("isPowerOfTwo %d\n", isPowerOfTwo(loop));
    }

    return 0;
}



/* Program to print size of datatypes: char, int, float, double 
 * We will use 'sizeof' operator to get the size of mentioned datatype
*/

int main()
{
	printf("Size of char = %lu\n", sizeof(char));
		   
	printf("Size of int = %lu\n", sizeof(int));
		   
	printf("Size of float = %lu\n", sizeof(float));
		   
	printf("Size of double = %lu\n", sizeof(double));
		   
    int year;  
    printf("Enter a year: ");  
    scanf("%d", &year);  
    if(((year%4 == 0) && (year%400 == 0)) || (year%100 != 0))  
    {  
        printf("%d is a leap year", year);  
    } else {  
        printf("%d is not a leap year", year);  
    }  
    getchar();        

    test_bitwise_operators();
         
	return 0;
}