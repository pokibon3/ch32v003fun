#include <Arduino.h>
#define LED_PIN D6
#define SPEED   125           // default time

const	char	table[][8] = {
	"A.-",
	"B-...",
	"C-.-.",
	"D-..",
	"E.",
	"F..-.",
	"G--.",
	"H....",
	"I..",
	"J.---",
	"K-.-",
	"L.-..",
	"M--",
	"N-.",
	"O---",
	"P.--.",
	"Q--.-",
	"R.-.",
	"S...",
	"T-",
	"U..-",
	"V...-",
	"W.--",
	"X-..-",
	"Y-.--",
	"Z--..",
	"1.----",
	"2..---",
	"3...--",
	"4....-",
	"5.....",
	"6-....",
	"7--...",
	"8---..",
	"9----.",
	"0-----",
/*
	"..-.-.-",
	",--..--",
	":---...",
	"?..--..",
	"'.----.",
	"--....-",
	"(-.--.",
	")-.--.-",
	"/-..-.",
	"=-...-",
	"+.-.-.",
	"\".-..-.",
	"*-..-",
	"@.--.-."
*/
};

void	short_beep()
{
    digitalWrite(LED_PIN, HIGH);
 	delay(SPEED);
    digitalWrite(LED_PIN, LOW);
 	delay(SPEED);
}

void	long_beep()
{
    digitalWrite(LED_PIN, HIGH);
 	delay(SPEED * 3);
    digitalWrite(LED_PIN, LOW);
 	delay(SPEED);
}

void	morse_chr(char chr)
{
	static	int16_t	cnt, i;

	if (chr == ' ') {
		delay(SPEED * 5);
		return;
	}

	for (cnt = 0; cnt < 36; cnt++) {
		if (table[cnt][0] == chr) {
			for (i = 1; table[cnt][i] != 0x00; i++) {
				if (table[cnt][i] == '.')
					short_beep();
				else
					long_beep();
			}
			delay(SPEED * 3);
			return;
		}
	}
}

void	morse_str(char* str)
{
	while (*str != 0x00) {
		morse_chr(*str);
		str++;
	}
}

void setup()
{
//    pinMode(LED_PIN, OUTPUT_OPENDRAIN);
    pinMode(LED_PIN, OUTPUT);
    morse_str("HI");
    delay(3000);
}

void loop()
{
    morse_str("VVV DE JA9OIR");
    delay(3000);

}

