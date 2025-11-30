/*
URL: https://leetcode.com/problems/valid-sudoku
*/

#include <iostream>
#include <vector>   
#include <array>
#include <bitset>       

bool isValidSudoku(const std::vector<std::vector<char>> &board)
{
    if (board.size() != 9 || board[0].size() != 9)
    {
        return false;
    }

    std::array<std::bitset<9>, 9> rows{};
    std::array<std::bitset<9>, 9> cols{};
    std::array<std::bitset<9>, 9> boxes{};

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            char currentChar = board[i][j];

            if (currentChar == '.')
            {
                continue;
            }

            int num = currentChar - '1'; // Convert char to int (0-8)
            int boxIndex = (i / 3) * 3 + j / 3;

            if (rows[i].test(num) || cols[j].test(num) || boxes[boxIndex].test(num))
            {
                return false;
            }

            rows[i].set(num);
            cols[j].set(num);
            boxes[boxIndex].set(num);
        }
    }
    return true;
}

int main()
{
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    if (isValidSudoku(board))
    {
        std::cout << "The Sudoku board is valid." << std::endl;
    }
    else
    {
        std::cout << "The Sudoku board is not valid." << std::endl;
    }

    return 0;
}