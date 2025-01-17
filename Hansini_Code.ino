#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int previousChar = 2; // Select previous character
const int upChar = 3;		// Set as previous character    (M => L)
const int downChar = 4;		// Set as next character        (M => N)
const int nextChar = 5;		// Select next character
const char chars[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const char words[][] = {{'A', 'B', 'L', 'E'}, {'A', 'C', 'I', 'D'}, {'A', 'G', 'E', 'D'}, {'A', 'L', 'S', 'O'}, {'A', 'R', 'E', 'A'}, {'A', 'R', 'M', 'Y'}, {'A', 'W', 'A', 'Y'}, {'B', 'A', 'B', 'Y'}, {'B', 'A', 'C', 'K'}, {'B', 'A', 'L', 'L'}, {'B', 'A', 'N', 'D'}, {'B', 'A', 'N', 'K'}, {'B', 'A', 'S', 'E'}, {'B', 'A', 'T', 'H'}, {'B', 'E', 'A', 'R'}, {'B', 'E', 'A', 'T'}, {'B', 'E', 'E', 'N'}, {'B', 'E', 'E', 'R'}, {'B', 'E', 'L', 'L'}, {'B', 'E', 'L', 'T'}, {'B', 'E', 'S', 'T'}, {'B', 'I', 'L', 'L'}, {'B', 'I', 'R', 'D'}, {'B', 'L', 'O', 'W'}, {'B', 'L', 'U', 'E'}, {'B', 'O', 'A', 'T'}, {'B', 'O', 'D', 'Y'}, {'B', 'O', 'M', 'B'}, {'B', 'O', 'N', 'D'}, {'B', 'O', 'N', 'E'}, {'B', 'O', 'O', 'K'}, {'B', 'O', 'O', 'M'}, {'B', 'O', 'R', 'N'}, {'B', 'O', 'S', 'S'}, {'B', 'O', 'T', 'H'}, {'B', 'O', 'W', 'L'}, {'B', 'U', 'L', 'K'}, {'B', 'U', 'R', 'N'}, {'B', 'U', 'S', 'H'}, {'B', 'U', 'S', 'Y'}, {'C', 'A', 'L', 'L'}, {'C', 'A', 'L', 'M'}, {'C', 'A', 'M', 'E'}, {'C', 'A', 'M', 'P'}, {'C', 'A', 'R', 'D'}, {'C', 'A', 'R', 'E'}, {'C', 'A', 'S', 'E'}, {'C', 'A', 'S', 'H'}, {'C', 'A', 'S', 'T'}, {'C', 'E', 'L', 'L'}, {'C', 'H', 'A', 'T'}, {'C', 'H', 'I', 'P'}, {'C', 'I', 'T', 'Y'}, {'C', 'L', 'U', 'B'}, {'C', 'O', 'A', 'L'}, {'C', 'O', 'A', 'T'}, {'C', 'O', 'D', 'E'}, {'C', 'O', 'L', 'D'}, {'C', 'O', 'M', 'E'}, {'C', 'O', 'O', 'K'}, {'C', 'O', 'O', 'L'}, {'C', 'O', 'P', 'E'}, {'C', 'O', 'P', 'Y'}, {'C', 'O', 'R', 'E'}, {'C', 'O', 'S', 'T'}, {'C', 'R', 'E', 'W'}, {'C', 'R', 'O', 'P'}, {'D', 'A', 'R', 'K'}, {'D', 'A', 'T', 'A'}, {'D', 'A', 'T', 'E'}, {'D', 'A', 'W', 'N'}, {'D', 'A', 'Y', 'S'}, {'D', 'E', 'A', 'D'}, {'D', 'E', 'A', 'L'}, {'D', 'E', 'A', 'N'}, {'D', 'E', 'A', 'R'}, {'D', 'E', 'B', 'T'}, {'D', 'E', 'E', 'P'}, {'D', 'E', 'N', 'Y'}, {'D', 'E', 'S', 'K'}, {'D', 'I', 'A', 'L'}, {'D', 'I', 'C', 'K'}, {'D', 'I', 'E', 'T'}, {'D', 'I', 'S', 'C'}, {'D', 'I', 'S', 'K'}, {'D', 'O', 'E', 'S'}, {'D', 'O', 'N', 'E'}, {'D', 'O', 'O', 'R'}, {'D', 'O', 'S', 'E'}, {'D', 'O', 'W', 'N'}, {'D', 'R', 'A', 'W'}, {'D', 'R', 'E', 'W'}, {'D', 'R', 'O', 'P'}, {'D', 'R', 'U', 'G'}, {'D', 'U', 'A', 'L'}, {'D', 'U', 'K', 'E'}, {'D', 'U', 'S', 'T'}, {'D', 'U', 'T', 'Y'}, {'E', 'A', 'C', 'H'}, {'E', 'A', 'R', 'N'}, {'E', 'A', 'S', 'E'}, {'E', 'A', 'S', 'T'}, {'E', 'A', 'S', 'Y'}, {'E', 'D', 'G', 'E'}, {'E', 'L', 'S', 'E'}, {'E', 'V', 'E', 'N'}, {'E', 'V', 'E', 'R'}, {'E', 'V', 'I', 'L'}, {'E', 'X', 'I', 'T'}, {'F', 'A', 'C', 'E'}, {'F', 'A', 'C', 'T'}, {'F', 'A', 'I', 'L'}, {'F', 'A', 'I', 'R'}, {'F', 'A', 'L', 'L'}, {'F', 'A', 'R', 'M'}, {'F', 'A', 'S', 'T'}, {'F', 'A', 'T', 'E'}, {'F', 'E', 'A', 'R'}, {'F', 'E', 'E', 'D'}, {'F', 'E', 'E', 'L'}, {'F', 'E', 'E', 'T'}, {'F', 'E', 'L', 'L'}, {'F', 'E', 'L', 'T'}, {'F', 'I', 'L', 'E'}, {'F', 'I', 'L', 'L'}, {'F', 'I', 'L', 'M'}, {'F', 'I', 'N', 'D'}, {'F', 'I', 'N', 'E'}, {'F', 'I', 'R', 'E'}, {'F', 'I', 'R', 'M'}, {'F', 'I', 'S', 'H'}, {'F', 'I', 'V', 'E'}, {'F', 'L', 'A', 'T'}, {'F', 'L', 'O', 'W'}, {'F', 'O', 'O', 'D'}, {'F', 'O', 'O', 'T'}, {'F', 'O', 'R', 'D'}, {'F', 'O', 'R', 'M'}, {'F', 'O', 'R', 'T'}, {'F', 'O', 'U', 'R'}, {'F', 'R', 'E', 'E'}, {'F', 'R', 'O', 'M'}, {'F', 'U', 'E', 'L'}, {'F', 'U', 'L', 'L'}, {'F', 'U', 'N', 'D'}, {'G', 'A', 'I', 'N'}, {'G', 'A', 'M', 'E'}, {'G', 'A', 'T', 'E'}, {'G', 'A', 'V', 'E'}, {'G', 'E', 'A', 'R'}, {'G', 'E', 'N', 'E'}, {'G', 'I', 'F', 'T'}, {'G', 'I', 'R', 'L'}, {'G', 'I', 'V', 'E'}, {'G', 'L', 'A', 'D'}, {'G', 'O', 'A', 'L'}, {'G', 'O', 'E', 'S'}, {'G', 'O', 'L', 'D'}, {'G', 'O', 'L', 'F'}, {'G', 'O', 'N', 'E'}, {'G', 'O', 'O', 'D'}, {'G', 'R', 'A', 'Y'}, {'G', 'R', 'E', 'W'}, {'G', 'R', 'E', 'Y'}, {'G', 'R', 'O', 'W'}, {'G', 'U', 'L', 'F'}, {'H', 'A', 'I', 'R'}, {'H', 'A', 'L', 'F'}, {'H', 'A', 'L', 'L'}, {'H', 'A', 'N', 'D'}, {'H', 'A', 'N', 'G'}, {'H', 'A', 'R', 'D'}, {'H', 'A', 'R', 'M'}, {'H', 'A', 'T', 'E'}, {'H', 'A', 'V', 'E'}, {'H', 'E', 'A', 'D'}, {'H', 'E', 'A', 'R'}, {'H', 'E', 'A', 'T'}, {'H', 'E', 'L', 'D'}, {'H', 'E', 'L', 'L'}, {'H', 'E', 'L', 'P'}, {'H', 'E', 'R', 'E'}, {'H', 'E', 'R', 'O'}, {'H', 'I', 'G', 'H'}, {'H', 'I', 'L', 'L'}, {'H', 'I', 'R', 'E'}, {'H', 'O', 'L', 'D'}, {'H', 'O', 'L', 'E'}, {'H', 'O', 'L', 'Y'}, {'H', 'O', 'M', 'E'}, {'H', 'O', 'P', 'E'}, {'H', 'O', 'S', 'T'}, {'H', 'O', 'U', 'R'}, {'H', 'U', 'G', 'E'}, {'H', 'U', 'N', 'G'}, {'H', 'U', 'N', 'T'}, {'H', 'U', 'R', 'T'}, {'I', 'D', 'E', 'A'}, {'I', 'N', 'C', 'H'}, {'I', 'N', 'T', 'O'}, {'I', 'R', 'O', 'N'}, {'I', 'T', 'E', 'M'}, {'J', 'A', 'C', 'K'}, {'J', 'A', 'N', 'E'}, {'J', 'E', 'A', 'N'}, {'J', 'O', 'H', 'N'}, {'J', 'O', 'I', 'N'}, {'J', 'U', 'M', 'P'}, {'J', 'U', 'R', 'Y'}, {'J', 'U', 'S', 'T'}, {'K', 'E', 'E', 'N'}, {'K', 'E', 'E', 'P'}, {'K', 'E', 'N', 'T'}, {'K', 'E', 'P', 'T'}, {'K', 'I', 'C', 'K'}, {'K', 'I', 'L', 'L'}, {'K', 'I', 'N', 'D'}, {'K', 'I', 'N', 'G'}, {'K', 'N', 'E', 'E'}, {'K', 'N', 'E', 'W'}, {'K', 'N', 'O', 'W'}, {'L', 'A', 'C', 'K'}, {'L', 'A', 'D', 'Y'}, {'L', 'A', 'I', 'D'}, {'L', 'A', 'K', 'E'}, {'L', 'A', 'N', 'D'}, {'L', 'A', 'N', 'E'}, {'L', 'A', 'S', 'T'}, {'L', 'A', 'T', 'E'}, {'L', 'E', 'A', 'D'}, {'L', 'E', 'F', 'T'}, {'L', 'E', 'S', 'S'}, {'L', 'I', 'F', 'E'}, {'L', 'I', 'F', 'T'}, {'L', 'I', 'K', 'E'}, {'L', 'I', 'N', 'E'}, {'L', 'I', 'N', 'K'}, {'L', 'I', 'S', 'T'}, {'L', 'I', 'V', 'E'}, {'L', 'O', 'A', 'D'}, {'L', 'O', 'A', 'N'}, {'L', 'O', 'C', 'K'}, {'L', 'O', 'G', 'O'}, {'L', 'O', 'N', 'G'}, {'L', 'O', 'O', 'K'}, {'L', 'O', 'R', 'D'}, {'L', 'O', 'S', 'E'}, {'L', 'O', 'S', 'S'}, {'L', 'O', 'S', 'T'}, {'L', 'O', 'V', 'E'}, {'L', 'U', 'C', 'K'}, {'M', 'A', 'D', 'E'}, {'M', 'A', 'I', 'L'}, {'M', 'A', 'I', 'N'}, {'M', 'A', 'K', 'E'}, {'M', 'A', 'L', 'E'}, {'M', 'A', 'N', 'Y'}, {'M', 'A', 'R', 'K'}, {'M', 'A', 'S', 'S'}, {'M', 'A', 'T', 'T'}, {'M', 'E', 'A', 'L'}, {'M', 'E', 'A', 'N'}, {'M', 'E', 'A', 'T'}, {'M', 'E', 'E', 'T'}, {'M', 'E', 'N', 'U'}, {'M', 'E', 'R', 'E'}, {'M', 'I', 'K', 'E'}, {'M', 'I', 'L', 'E'}, {'M', 'I', 'L', 'K'}, {'M', 'I', 'L', 'L'}, {'M', 'I', 'N', 'D'}, {'M', 'I', 'N', 'E'}, {'M', 'I', 'S', 'S'}, {'M', 'O', 'D', 'E'}, {'M', 'O', 'O', 'D'}, {'M', 'O', 'O', 'N'}, {'M', 'O', 'R', 'E'}, {'M', 'O', 'S', 'T'}, {'M', 'O', 'V', 'E'}, {'M', 'U', 'C', 'H'}, {'M', 'U', 'S', 'T'}, {'N', 'A', 'M', 'E'}, {'N', 'A', 'V', 'Y'}, {'N', 'E', 'A', 'R'}, {'N', 'E', 'C', 'K'}, {'N', 'E', 'E', 'D'}, {'N', 'E', 'W', 'S'}, {'N', 'E', 'X', 'T'}, {'N', 'I', 'C', 'E'}, {'N', 'I', 'C', 'K'}, {'N', 'I', 'N', 'E'}, {'N', 'O', 'N', 'E'}, {'N', 'O', 'S', 'E'}, {'N', 'O', 'T', 'E'}, {'O', 'K', 'A', 'Y'}, {'O', 'N', 'C', 'E'}, {'O', 'N', 'L', 'Y'}, {'O', 'N', 'T', 'O'}, {'O', 'P', 'E', 'N'}, {'O', 'R', 'A', 'L'}, {'O', 'V', 'E', 'R'}, {'P', 'A', 'C', 'E'}, {'P', 'A', 'C', 'K'}, {'P', 'A', 'G', 'E'}, {'P', 'A', 'I', 'D'}, {'P', 'A', 'I', 'N'}, {'P', 'A', 'I', 'R'}, {'P', 'A', 'L', 'M'}, {'P', 'A', 'R', 'K'}, {'P', 'A', 'R', 'T'}, {'P', 'A', 'S', 'S'}, {'P', 'A', 'S', 'T'}, {'P', 'A', 'T', 'H'}, {'P', 'E', 'A', 'K'}, {'P', 'I', 'C', 'K'}, {'P', 'I', 'N', 'K'}, {'P', 'I', 'P', 'E'}, {'P', 'L', 'A', 'N'}, {'P', 'L', 'A', 'Y'}, {'P', 'L', 'O', 'T'}, {'P', 'L', 'U', 'G'}, {'P', 'L', 'U', 'S'}, {'P', 'O', 'L', 'L'}, {'P', 'O', 'O', 'L'}, {'P', 'O', 'O', 'R'}, {'P', 'O', 'R', 'T'}, {'P', 'O', 'S', 'T'}, {'P', 'U', 'L', 'L'}, {'P', 'U', 'R', 'E'}, {'P', 'U', 'S', 'H'}, {'R', 'A', 'C', 'E'}, {'R', 'A', 'I', 'L'}, {'R', 'A', 'I', 'N'}, {'R', 'A', 'N', 'K'}, {'R', 'A', 'R', 'E'}, {'R', 'A', 'T', 'E'}, {'R', 'E', 'A', 'D'}, {'R', 'E', 'A', 'L'}, {'R', 'E', 'A', 'R'}, {'R', 'E', 'L', 'Y'}, {'R', 'E', 'N', 'T'}, {'R', 'E', 'S', 'T'}, {'R', 'I', 'C', 'E'}, {'R', 'I', 'C', 'H'}, {'R', 'I', 'D', 'E'}, {'R', 'I', 'N', 'G'}, {'R', 'I', 'S', 'E'}, {'R', 'I', 'S', 'K'}, {'R', 'O', 'A', 'D'}, {'R', 'O', 'C', 'K'}, {'R', 'O', 'L', 'E'}, {'R', 'O', 'L', 'L'}, {'R', 'O', 'O', 'F'}, {'R', 'O', 'O', 'M'}, {'R', 'O', 'O', 'T'}, {'R', 'O', 'S', 'E'}, {'R', 'U', 'L', 'E'}, {'R', 'U', 'S', 'H'}, {'R', 'U', 'T', 'H'}, {'S', 'A', 'F', 'E'}, {'S', 'A', 'I', 'D'}, {'S', 'A', 'K', 'E'}, {'S', 'A', 'L', 'E'}, {'S', 'A', 'L', 'T'}, {'S', 'A', 'M', 'E'}, {'S', 'A', 'N', 'D'}, {'S', 'A', 'V', 'E'}, {'S', 'E', 'A', 'T'}, {'S', 'E', 'E', 'D'}, {'S', 'E', 'E', 'K'}, {'S', 'E', 'E', 'M'}, {'S', 'E', 'E', 'N'}, {'S', 'E', 'L', 'F'}, {'S', 'E', 'L', 'L'}, {'S', 'E', 'N', 'D'}, {'S', 'E', 'N', 'T'}, {'S', 'E', 'P', 'T'}, {'S', 'H', 'I', 'P'}, {'S', 'H', 'O', 'P'}, {'S', 'H', 'O', 'T'}, {'S', 'H', 'O', 'W'}, {'S', 'H', 'U', 'T'}, {'S', 'I', 'C', 'K'}, {'S', 'I', 'D', 'E'}, {'S', 'I', 'G', 'N'}, {'S', 'I', 'T', 'E'}, {'S', 'I', 'Z', 'E'}, {'S', 'K', 'I', 'N'}, {'S', 'L', 'I', 'P'}, {'S', 'L', 'O', 'W'}, {'S', 'N', 'O', 'W'}, {'S', 'O', 'F', 'T'}, {'S', 'O', 'I', 'L'}, {'S', 'O', 'L', 'D'}, {'S', 'O', 'L', 'E'}, {'S', 'O', 'M', 'E'}, {'S', 'O', 'N', 'G'}, {'S', 'O', 'O', 'N'}, {'S', 'O', 'R', 'T'}, {'S', 'O', 'U', 'L'}, {'S', 'P', 'O', 'T'}, {'S', 'T', 'A', 'R'}, {'S', 'T', 'A', 'Y'}, {'S', 'T', 'E', 'P'}, {'S', 'T', 'O', 'P'}, {'S', 'U', 'C', 'H'}, {'S', 'U', 'I', 'T'}, {'S', 'U', 'R', 'E'}, {'T', 'A', 'K', 'E'}, {'T', 'A', 'L', 'E'}, {'T', 'A', 'L', 'K'}, {'T', 'A', 'L', 'L'}, {'T', 'A', 'N', 'K'}, {'T', 'A', 'P', 'E'}, {'T', 'A', 'S', 'K'}, {'T', 'E', 'A', 'M'}, {'T', 'E', 'C', 'H'}, {'T', 'E', 'L', 'L'}, {'T', 'E', 'N', 'D'}, {'T', 'E', 'R', 'M'}, {'T', 'E', 'S', 'T'}, {'T', 'E', 'X', 'T'}, {'T', 'H', 'A', 'N'}, {'T', 'H', 'A', 'T'}, {'T', 'H', 'E', 'M'}, {'T', 'H', 'E', 'N'}, {'T', 'H', 'E', 'Y'}, {'T', 'H', 'I', 'N'}, {'T', 'H', 'I', 'S'}, {'T', 'H', 'U', 'S'}, {'T', 'I', 'L', 'L'}, {'T', 'I', 'M', 'E'}, {'T', 'I', 'N', 'Y'}, {'T', 'O', 'L', 'D'}, {'T', 'O', 'L', 'L'}, {'T', 'O', 'N', 'E'}, {'T', 'O', 'N', 'Y'}, {'T', 'O', 'O', 'K'}, {'T', 'O', 'O', 'L'}, {'T', 'O', 'U', 'R'}, {'T', 'O', 'W', 'N'}, {'T', 'R', 'E', 'E'}, {'T', 'R', 'I', 'P'}, {'T', 'R', 'U', 'E'}, {'T', 'U', 'N', 'E'}, {'T', 'U', 'R', 'N'}, {'T', 'W', 'I', 'N'}, {'T', 'Y', 'P', 'E'}, {'U', 'N', 'I', 'T'}, {'U', 'P', 'O', 'N'}, {'U', 'S', 'E', 'D'}, {'U', 'S', 'E', 'R'}, {'V', 'A', 'R', 'Y'}, {'V', 'A', 'S', 'T'}, {'V', 'E', 'R', 'Y'}, {'V', 'I', 'C', 'E'}, {'V', 'I', 'E', 'W'}, {'V', 'O', 'T', 'E'}, {'W', 'A', 'G', 'E'}, {'W', 'A', 'I', 'T'}, {'W', 'A', 'K', 'E'}, {'W', 'A', 'L', 'K'}, {'W', 'A', 'L', 'L'}, {'W', 'A', 'N', 'T'}, {'W', 'A', 'R', 'D'}, {'W', 'A', 'R', 'M'}, {'W', 'A', 'S', 'H'}, {'W', 'A', 'V', 'E'}, {'W', 'A', 'Y', 'S'}, {'W', 'E', 'A', 'K'}, {'W', 'E', 'A', 'R'}, {'W', 'E', 'E', 'K'}, {'W', 'E', 'L', 'L'}, {'W', 'E', 'N', 'T'}, {'W', 'E', 'R', 'E'}, {'W', 'E', 'S', 'T'}, {'W', 'H', 'A', 'T'}, {'W', 'H', 'E', 'N'}, {'W', 'H', 'O', 'M'}, {'W', 'I', 'D', 'E'}, {'W', 'I', 'F', 'E'}, {'W', 'I', 'L', 'D'}, {'W', 'I', 'L', 'L'}, {'W', 'I', 'N', 'D'}, {'W', 'I', 'N', 'E'}, {'W', 'I', 'N', 'G'}, {'W', 'I', 'R', 'E'}, {'W', 'I', 'S', 'E'}, {'W', 'I', 'S', 'H'}, {'W', 'I', 'T', 'H'}, {'W', 'O', 'O', 'D'}, {'W', 'O', 'R', 'D'}, {'W', 'O', 'R', 'E'}, {'W', 'O', 'R', 'K'}, {'Y', 'A', 'R', 'D'}, {'Y', 'E', 'A', 'H'}, {'Y', 'E', 'A', 'R'}, {'Y', 'O', 'U', 'R'}, {'Z', 'E', 'R', 'O'}, {'Z', 'O', 'N', 'E'}};

int numTries;
int typeIndex = 0;
int charIndex = 0;
char word[] = {'A', 'A', 'A', 'A'};
char randomWord[];

bool startGame = false;

void setup()
{
	// initialize LCD
	lcd.init();
	lcd.backlight();
	// initialize the pushbutton pin as an input:
	pinMode(previousChar, INPUT);
	pinMode(upChar, INPUT);
	pinMode(downChar, INPUT);
	pinMode(nextChar, INPUT);
}

void loop()
{
	if (!startGame)
	{
		// TODO: choose random word
		numTries = 5;
		startGame = true;
		return;
	}

	if (numTries <= 0)
	{
		loseSequence();
	}

	if (digitalRead(previousChar) == HIGH)
	{
		typeIndex--;
		if (typeIndex < 0)
			typeIndex = 0;
	}
	if (digitalRead(upChar) == HIGH)
	{
		charIndex--;
		if (charIndex < 0)
			charIndex = sizeof(chars) - 1;
	}
	if (digitalRead(downChar) == HIGH)
	{
		charIndex++;
		if (charIndex >= 26)
			charIndex = 0;
	}
	if (digitalRead(nextChar) == HIGH)
	{
		typeIndex++;
		if (typeIndex >= 4)
			checkWord();
	}

	lcd.setCursor(5 + typeIndex, 1);
	lcd.print(chars[charIndex]);
	word[typeIndex] = chars[charIndex];

	delay(170);
}

void checkWord()
{
	numTries--;
	int correctCounter = 0;

	for (int i = 0; i < sizeof(word); i++)
	{
		if (word[i] == randomWord[i])
		{
			correctCounter++;
			// TODO: light up green LED
		}
		else if (isInArr(word[i], randomWord))
		{
			// TODO: light up yellow LED
		}
		else
		{
			// TODO: light up blue LED
		}
	}
	delay(1000);
	// TODO: turn off all LEDs

	if (correctCounter >= 4)
	{
		winSequence();
	}
}

bool isInArr(char element, char[] array)
{
	for (char a : array)
	{
		if (element == a)
			return true;
	}
	return false;
}

void winSequence()
{
	startGame = false;
	// TODO: make a win sequence
}

void loseSequence()
{
	startGame = false;
	// TODO: make a lose sequence
}