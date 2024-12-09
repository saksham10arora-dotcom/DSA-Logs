```cpp
// LeetCode problem 2296: Design A Text Editor, https://leetcode.com/problems/design-a-text-editor/
// Brief description: Design a text editor with basic operations.

#include <iostream>
#include <string>
#include <vector>

class TextEditor {
public:
    std::string text;
    int cursor;

    TextEditor() : cursor(0) {}

    void addText(const std::string& text_to_add) {
        // Brute force approach: O(n) complexity, where n is the length of the text
        // We can simply insert the new text at the current cursor position
        text.insert(cursor, text_to_add);
        cursor += text_to_add.length();
    }

    int deleteText(int k) {
        // Brute force approach: O(n) complexity, where n is the number of characters to delete
        // We can simply remove the last k characters from the text
        int deleted = 0;
        while (cursor > 0 && deleted < k) {
            cursor--;
            text.erase(cursor);
            deleted++;
        }
        return deleted;
    }

    std::string cursorLeft(int k) {
        // Brute force approach: O(n) complexity, where n is the number of positions to move
        // We can simply move the cursor to the left by k positions
        cursor = std::max(0, cursor - k);
        return text.substr(cursor, 10);
    }

    std::string cursorRight(int k) {
        // Brute force approach: O(n) complexity, where n is the number of positions to move
        // We can simply move the cursor to the right by k positions
        cursor = std::min((int)text.length(), cursor + k);
        return text.substr(cursor, 10);
    }
};

int main() {
    TextEditor editor;
    editor.addText("hello");
    std::cout << editor.cursorLeft(3) << std::endl;  // Output: "l"
    editor.addText(" world");
    std::cout << editor.cursorRight(8) << std::endl;  // Output: "r"
    std::cout << editor.deleteText(4) << std::endl;  // Output: 4
    std::cout << editor.cursorLeft(2) << std::endl;  // Output: " "
    std::cout << editor.cursorRight(6) << std::endl;  // Output: "d"
    return 0;
}
```