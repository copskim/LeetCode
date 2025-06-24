class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        const vector<unsigned char> rev4bt{ 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13,
            3, 11, 7, 15 };
        uint32_t res{};
        for (int i = 0; i < 32; i += 4) {
            uint32_t s4b = (n & ((0x0000000f) << i)) >> i;
            res |= ((rev4bt[s4b]) << (32 - i - 4));
        }
        return res;
    }
};