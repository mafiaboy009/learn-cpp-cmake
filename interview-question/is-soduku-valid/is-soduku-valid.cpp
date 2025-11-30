#include <vector>
#include <unordered_set>
#include <iostream>

bool isValidSudoku(const std::vector<std::vector<char>> &board)
{
    if (board.size() != 9 || board[0].size() != 9)
    {
        return false;
    }

    std::unordered_set<char> row[9];
    std::unordered_set<char> col[9];
    std::unordered_set<char> box[9];

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            // Calculate the index for the 3x3 sub-box: (row / 3) * 3 + (col / 3)
                        int boxIndex = (i / 3) * 3 + j / 3;
            char currentChar = board[i][j];

            if (currentChar == '.')
            {
                continue;
            }

            if (row[i].count(currentChar))
            {
                return false;
            }
            row[i].insert(currentChar);

            if (col[j].count(currentChar))
            {
                return false;
            }
            col[j].insert(currentChar);

            if (box[boxIndex].count(currentChar))
            {
                return false;
            }
            box[boxIndex].insert(currentChar);
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
        std::cout << "The Sudoku board is invalid." << std::endl;
    }

    return 0;
}