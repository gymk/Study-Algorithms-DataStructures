#include <iostream>
#include <stdlib.h>
#include <bitset>

int main(void)
{
  int i = 0, v, f;
	v = 0;
	do
	{
		int f = (v & (v - 1));
		std::cout << "Val: [" << v << ", " << std::bitset<32>(v) << "], its diff &: [" << f << ", " << std::bitset<32>(f) << "], DiffVal: [" << v-f << ", " << std::bitset<32>(v-f) << "]\n";
		v = rand() % 20000;
    i++;
	} while(i < 100);
	return 0;
}

/*
Output:
	Val: [0, 00000000000000000000000000000000], its diff &: [0, 00000000000000000000000000000000], DiffVal: [0, 00000000000000000000000000000000]
	Val: [9383, 00000000000000000010010010100111], its diff &: [9382, 00000000000000000010010010100110], DiffVal: [1, 00000000000000000000000000000001]
	Val: [10886, 00000000000000000010101010000110], its diff &: [10884, 00000000000000000010101010000100], DiffVal: [2, 00000000000000000000000000000010]
	Val: [12777, 00000000000000000011000111101001], its diff &: [12776, 00000000000000000011000111101000], DiffVal: [1, 00000000000000000000000000000001]
	Val: [16915, 00000000000000000100001000010011], its diff &: [16914, 00000000000000000100001000010010], DiffVal: [1, 00000000000000000000000000000001]
	Val: [7793, 00000000000000000001111001110001], its diff &: [7792, 00000000000000000001111001110000], DiffVal: [1, 00000000000000000000000000000001]
	Val: [18335, 00000000000000000100011110011111], its diff &: [18334, 00000000000000000100011110011110], DiffVal: [1, 00000000000000000000000000000001]
	Val: [5386, 00000000000000000001010100001010], its diff &: [5384, 00000000000000000001010100001000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [492, 00000000000000000000000111101100], its diff &: [488, 00000000000000000000000111101000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [16649, 00000000000000000100000100001001], its diff &: [16648, 00000000000000000100000100001000], DiffVal: [1, 00000000000000000000000000000001]
	Val: [1421, 00000000000000000000010110001101], its diff &: [1420, 00000000000000000000010110001100], DiffVal: [1, 00000000000000000000000000000001]
	Val: [2362, 00000000000000000000100100111010], its diff &: [2360, 00000000000000000000100100111000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [10027, 00000000000000000010011100101011], its diff &: [10026, 00000000000000000010011100101010], DiffVal: [1, 00000000000000000000000000000001]
	Val: [8690, 00000000000000000010000111110010], its diff &: [8688, 00000000000000000010000111110000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [59, 00000000000000000000000000111011], its diff &: [58, 00000000000000000000000000111010], DiffVal: [1, 00000000000000000000000000000001]
	Val: [17763, 00000000000000000100010101100011], its diff &: [17762, 00000000000000000100010101100010], DiffVal: [1, 00000000000000000000000000000001]
	Val: [13926, 00000000000000000011011001100110], its diff &: [13924, 00000000000000000011011001100100], DiffVal: [2, 00000000000000000000000000000010]
	Val: [540, 00000000000000000000001000011100], its diff &: [536, 00000000000000000000001000011000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [3426, 00000000000000000000110101100010], its diff &: [3424, 00000000000000000000110101100000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [9172, 00000000000000000010001111010100], its diff &: [9168, 00000000000000000010001111010000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [15736, 00000000000000000011110101111000], its diff &: [15728, 00000000000000000011110101110000], DiffVal: [8, 00000000000000000000000000001000]
	Val: [5211, 00000000000000000001010001011011], its diff &: [5210, 00000000000000000001010001011010], DiffVal: [1, 00000000000000000000000000000001]
	Val: [15368, 00000000000000000011110000001000], its diff &: [15360, 00000000000000000011110000000000], DiffVal: [8, 00000000000000000000000000001000]
	Val: [2567, 00000000000000000000101000000111], its diff &: [2566, 00000000000000000000101000000110], DiffVal: [1, 00000000000000000000000000000001]
	Val: [16429, 00000000000000000100000000101101], its diff &: [16428, 00000000000000000100000000101100], DiffVal: [1, 00000000000000000000000000000001]
	Val: [5782, 00000000000000000001011010010110], its diff &: [5780, 00000000000000000001011010010100], DiffVal: [2, 00000000000000000000000000000010]
	Val: [1530, 00000000000000000000010111111010], its diff &: [1528, 00000000000000000000010111111000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [2862, 00000000000000000000101100101110], its diff &: [2860, 00000000000000000000101100101100], DiffVal: [2, 00000000000000000000000000000010]
	Val: [5123, 00000000000000000001010000000011], its diff &: [5122, 00000000000000000001010000000010], DiffVal: [1, 00000000000000000000000000000001]
	Val: [14067, 00000000000000000011011011110011], its diff &: [14066, 00000000000000000011011011110010], DiffVal: [1, 00000000000000000000000000000001]
	Val: [3135, 00000000000000000000110000111111], its diff &: [3134, 00000000000000000000110000111110], DiffVal: [1, 00000000000000000000000000000001]
	Val: [13929, 00000000000000000011011001101001], its diff &: [13928, 00000000000000000011011001101000], DiffVal: [1, 00000000000000000000000000000001]
	Val: [19802, 00000000000000000100110101011010], its diff &: [19800, 00000000000000000100110101011000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [14022, 00000000000000000011011011000110], its diff &: [14020, 00000000000000000011011011000100], DiffVal: [2, 00000000000000000000000000000010]
	Val: [3058, 00000000000000000000101111110010], its diff &: [3056, 00000000000000000000101111110000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [13069, 00000000000000000011001100001101], its diff &: [13068, 00000000000000000011001100001100], DiffVal: [1, 00000000000000000000000000000001]
	Val: [18167, 00000000000000000100011011110111], its diff &: [18166, 00000000000000000100011011110110], DiffVal: [1, 00000000000000000000000000000001]
	Val: [1393, 00000000000000000000010101110001], its diff &: [1392, 00000000000000000000010101110000], DiffVal: [1, 00000000000000000000000000000001]
	Val: [18456, 00000000000000000100100000011000], its diff &: [18448, 00000000000000000100100000010000], DiffVal: [8, 00000000000000000000000000001000]
	Val: [15011, 00000000000000000011101010100011], its diff &: [15010, 00000000000000000011101010100010], DiffVal: [1, 00000000000000000000000000000001]
	Val: [18042, 00000000000000000100011001111010], its diff &: [18040, 00000000000000000100011001111000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [16229, 00000000000000000011111101100101], its diff &: [16228, 00000000000000000011111101100100], DiffVal: [1, 00000000000000000000000000000001]
	Val: [17373, 00000000000000000100001111011101], its diff &: [17372, 00000000000000000100001111011100], DiffVal: [1, 00000000000000000000000000000001]
	Val: [4421, 00000000000000000001000101000101], its diff &: [4420, 00000000000000000001000101000100], DiffVal: [1, 00000000000000000000000000000001]
	Val: [4919, 00000000000000000001001100110111], its diff &: [4918, 00000000000000000001001100110110], DiffVal: [1, 00000000000000000000000000000001]
	Val: [13784, 00000000000000000011010111011000], its diff &: [13776, 00000000000000000011010111010000], DiffVal: [8, 00000000000000000000000000001000]
	Val: [18537, 00000000000000000100100001101001], its diff &: [18536, 00000000000000000100100001101000], DiffVal: [1, 00000000000000000000000000000001]
	Val: [15198, 00000000000000000011101101011110], its diff &: [15196, 00000000000000000011101101011100], DiffVal: [2, 00000000000000000000000000000010]
	Val: [14324, 00000000000000000011011111110100], its diff &: [14320, 00000000000000000011011111110000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [18315, 00000000000000000100011110001011], its diff &: [18314, 00000000000000000100011110001010], DiffVal: [1, 00000000000000000000000000000001]
	Val: [4370, 00000000000000000001000100010010], its diff &: [4368, 00000000000000000001000100010000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [6413, 00000000000000000001100100001101], its diff &: [6412, 00000000000000000001100100001100], DiffVal: [1, 00000000000000000000000000000001]
	Val: [3526, 00000000000000000000110111000110], its diff &: [3524, 00000000000000000000110111000100], DiffVal: [2, 00000000000000000000000000000010]
	Val: [16091, 00000000000000000011111011011011], its diff &: [16090, 00000000000000000011111011011010], DiffVal: [1, 00000000000000000000000000000001]
	Val: [8980, 00000000000000000010001100010100], its diff &: [8976, 00000000000000000010001100010000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [19956, 00000000000000000100110111110100], its diff &: [19952, 00000000000000000100110111110000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [1873, 00000000000000000000011101010001], its diff &: [1872, 00000000000000000000011101010000], DiffVal: [1, 00000000000000000000000000000001]
	Val: [6862, 00000000000000000001101011001110], its diff &: [6860, 00000000000000000001101011001100], DiffVal: [2, 00000000000000000000000000000010]
	Val: [19170, 00000000000000000100101011100010], its diff &: [19168, 00000000000000000100101011100000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [6996, 00000000000000000001101101010100], its diff &: [6992, 00000000000000000001101101010000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [17281, 00000000000000000100001110000001], its diff &: [17280, 00000000000000000100001110000000], DiffVal: [1, 00000000000000000000000000000001]
	Val: [2305, 00000000000000000000100100000001], its diff &: [2304, 00000000000000000000100100000000], DiffVal: [1, 00000000000000000000000000000001]
	Val: [925, 00000000000000000000001110011101], its diff &: [924, 00000000000000000000001110011100], DiffVal: [1, 00000000000000000000000000000001]
	Val: [17084, 00000000000000000100001010111100], its diff &: [17080, 00000000000000000100001010111000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [16327, 00000000000000000011111111000111], its diff &: [16326, 00000000000000000011111111000110], DiffVal: [1, 00000000000000000000000000000001]
	Val: [336, 00000000000000000000000101010000], its diff &: [320, 00000000000000000000000101000000], DiffVal: [16, 00000000000000000000000000010000]
	Val: [6505, 00000000000000000001100101101001], its diff &: [6504, 00000000000000000001100101101000], DiffVal: [1, 00000000000000000000000000000001]
	Val: [10846, 00000000000000000010101001011110], its diff &: [10844, 00000000000000000010101001011100], DiffVal: [2, 00000000000000000000000000000010]
	Val: [1729, 00000000000000000000011011000001], its diff &: [1728, 00000000000000000000011011000000], DiffVal: [1, 00000000000000000000000000000001]
	Val: [1313, 00000000000000000000010100100001], its diff &: [1312, 00000000000000000000010100100000], DiffVal: [1, 00000000000000000000000000000001]
	Val: [5857, 00000000000000000001011011100001], its diff &: [5856, 00000000000000000001011011100000], DiffVal: [1, 00000000000000000000000000000001]
	Val: [16124, 00000000000000000011111011111100], its diff &: [16120, 00000000000000000011111011111000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [13895, 00000000000000000011011001000111], its diff &: [13894, 00000000000000000011011001000110], DiffVal: [1, 00000000000000000000000000000001]
	Val: [19582, 00000000000000000100110001111110], its diff &: [19580, 00000000000000000100110001111100], DiffVal: [2, 00000000000000000000000000000010]
	Val: [545, 00000000000000000000001000100001], its diff &: [544, 00000000000000000000001000100000], DiffVal: [1, 00000000000000000000000000000001]
	Val: [18814, 00000000000000000100100101111110], its diff &: [18812, 00000000000000000100100101111100], DiffVal: [2, 00000000000000000000000000000010]
	Val: [13367, 00000000000000000011010000110111], its diff &: [13366, 00000000000000000011010000110110], DiffVal: [1, 00000000000000000000000000000001]
	Val: [15434, 00000000000000000011110001001010], its diff &: [15432, 00000000000000000011110001001000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [10364, 00000000000000000010100001111100], its diff &: [10360, 00000000000000000010100001111000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [4043, 00000000000000000000111111001011], its diff &: [4042, 00000000000000000000111111001010], DiffVal: [1, 00000000000000000000000000000001]
	Val: [13750, 00000000000000000011010110110110], its diff &: [13748, 00000000000000000011010110110100], DiffVal: [2, 00000000000000000000000000000010]
	Val: [11087, 00000000000000000010101101001111], its diff &: [11086, 00000000000000000010101101001110], DiffVal: [1, 00000000000000000000000000000001]
	Val: [6808, 00000000000000000001101010011000], its diff &: [6800, 00000000000000000001101010010000], DiffVal: [8, 00000000000000000000000000001000]
	Val: [17276, 00000000000000000100001101111100], its diff &: [17272, 00000000000000000100001101111000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [7178, 00000000000000000001110000001010], its diff &: [7176, 00000000000000000001110000001000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [15788, 00000000000000000011110110101100], its diff &: [15784, 00000000000000000011110110101000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [13584, 00000000000000000011010100010000], its diff &: [13568, 00000000000000000011010100000000], DiffVal: [16, 00000000000000000000000000010000]
	Val: [5403, 00000000000000000001010100011011], its diff &: [5402, 00000000000000000001010100011010], DiffVal: [1, 00000000000000000000000000000001]
	Val: [2651, 00000000000000000000101001011011], its diff &: [2650, 00000000000000000000101001011010], DiffVal: [1, 00000000000000000000000000000001]
	Val: [12754, 00000000000000000011000111010010], its diff &: [12752, 00000000000000000011000111010000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [12399, 00000000000000000011000001101111], its diff &: [12398, 00000000000000000011000001101110], DiffVal: [1, 00000000000000000000000000000001]
	Val: [19932, 00000000000000000100110111011100], its diff &: [19928, 00000000000000000100110111011000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [15060, 00000000000000000011101011010100], its diff &: [15056, 00000000000000000011101011010000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [9676, 00000000000000000010010111001100], its diff &: [9672, 00000000000000000010010111001000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [13368, 00000000000000000011010000111000], its diff &: [13360, 00000000000000000011010000110000], DiffVal: [8, 00000000000000000000000000001000]
	Val: [7739, 00000000000000000001111000111011], its diff &: [7738, 00000000000000000001111000111010], DiffVal: [1, 00000000000000000000000000000001]
	Val: [10012, 00000000000000000010011100011100], its diff &: [10008, 00000000000000000010011100011000], DiffVal: [4, 00000000000000000000000000000100]
	Val: [16226, 00000000000000000011111101100010], its diff &: [16224, 00000000000000000011111101100000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [18586, 00000000000000000100100010011010], its diff &: [18584, 00000000000000000100100010011000], DiffVal: [2, 00000000000000000000000000000010]
	Val: [8094, 00000000000000000001111110011110], its diff &: [8092, 00000000000000000001111110011100], DiffVal: [2, 00000000000000000000000000000010]
*/
