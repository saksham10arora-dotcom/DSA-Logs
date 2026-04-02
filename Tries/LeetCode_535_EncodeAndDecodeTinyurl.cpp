```cpp
// LeetCode problem 535: Encode And Decode Tinyurl
// https://leetcode.com/problems/encode-and-decode-tinyurl/
// This problem requires designing a TinyURL system that can encode and decode URLs.

// Brute force approach: Using a map to store the encoded and decoded URLs (O(1) for encode and decode operations)
// However, this approach does not guarantee the uniqueness of the encoded URLs.

class Codec {
private:
    unordered_map<string, string> longToShort;
    unordered_map<string, string> shortToLong;
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<int> dis;

public:
    Codec() : gen(rd()), dis(0, chars.size() - 1) {}

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (longToShort.find(longUrl) != longToShort.end()) {
            return longToShort[longUrl];
        }
        string shortUrl = "http://tinyurl.com/";
        while (true) {
            string code;
            for (int i = 0; i < 6; i++) {
                code += chars[dis(gen)];
            }
            shortUrl += code;
            if (shortToLong.find(shortUrl) == shortToLong.end()) {
                break;
            }
        }
        longToShort[longUrl] = shortUrl;
        shortToLong[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortToLong[shortUrl];
    }
};

int main() {
    Codec codec;
    string longUrl1 = "https://leetcode.com/problems/design-tinyurl";
    string shortUrl1 = codec.encode(longUrl1);
    cout << "Encoded URL: " << shortUrl1 << endl;
    cout << "Decoded URL: " << codec.decode(shortUrl1) << endl;

    string longUrl2 = "https://leetcode.com/problems/design-tinyurl-2";
    string shortUrl2 = codec.encode(longUrl2);
    cout << "Encoded URL: " << shortUrl2 << endl;
    cout << "Decoded URL: " << codec.decode(shortUrl2) << endl;

    string longUrl3 = "https://leetcode.com/problems/design-tinyurl-3";
    string shortUrl3 = codec.encode(longUrl3);
    cout << "Encoded URL: " << shortUrl3 << endl;
    cout << "Decoded URL: " << codec.decode(shortUrl3) << endl;

    return 0;
}
```