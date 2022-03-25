#include <iostream>
#include <string>
#include <vector>
#include <ranges>
#include <algorithm>
#include <functional>
using namespace std;

struct position
{
    int x, y;
};

const position pos[8]{{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

string board[8];
bool visited[8][8];

vector<string> find_word(int size_of_board, vector<string> board, int word_number, vector<pair<string, bool>> word_list)
{
    vector<string> result;

    function<bool(int, int, int, string)> has_word = [&](int idx, int y, int x, string word)
    {
        if (idx == word.length())
        {
            return true;
        }

        visited[y][x] = true;
        bool board_has_word = false;

        for (int i = 0; i < 8; i++)
        {
            if (board_has_word)
                break;

            int next_y = y + pos[i].y;
            int next_x = x + pos[i].x;

            if (0 <= next_y && next_y < size_of_board && 0 <= next_x && next_x < size_of_board && !visited[next_y][next_x])
            {
                if (board[next_y][next_x] == 'q')
                {
                    if (idx < word.length() - 1 && word[idx] == 'q' && word[idx + 1] == 'u')
                        board_has_word = has_word(idx + 2, next_y, next_x, word);
                }
                else if (board[next_y][next_x] == word[idx])
                {
                    board_has_word = has_word(idx + 1, next_y, next_x, word);
                }
            }
        }
        visited[y][x] = false;
        return board_has_word;
    };

    for (int index = 0; index < word_number; index++)
    {
        for (int i = 0; i < size_of_board; i++)
        {
            for (int j = 0; j < size_of_board; j++)
            {
                bool board_has_word = false;
                if (board[i][j] == 'q')
                {
                    if (!word_list[index].second && word_list[index].first.length() >= 2 && word_list[index].first[0] == 'q' && word_list[index].first[1] == 'u')
                    {
                        board_has_word = has_word(2, i, j, word_list[index].first);
                    }
                }
                else if (!word_list[index].second && board[i][j] == word_list[index].first[0])
                {
                    board_has_word = has_word(1, i, j, word_list[index].first);
                }

                if (board_has_word)
                {
                    word_list[index].second = true;
                    result.push_back(word_list[index].first);
                }
            }
        }
    }
    return result;
}

pair<int, vector<string>> get_input()
{
    int input_amount{};
    string input{};

    cin >> input_amount;
    vector<string> input_list(input_amount);
    for (auto &elem : input_list)
    {
        cin >> elem;
    }
    return pair<int, vector<string>>{input_amount, input_list};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    auto [word_number, word_list_temp] = get_input();
    vector<pair<string, bool>> word_list(word_number);
    ranges::transform(word_list_temp, word_list.begin(), [](const string word)
                      { return pair<string, bool>{word, false}; });

    while (true)
    {
        auto [size_of_board, board]{get_input()};
        if (size_of_board == 0)
        {
            break;
        }

        for (int i = 0; i < word_number; i++)
        {
            word_list[i].second = false;
        }

        vector<string> result{find_word(size_of_board, board, word_number, word_list)};

        ranges::sort(result);
        ranges::for_each(result, [](const string &str)
                         { cout << str << "\n"; });
        cout << "-\n";
    }
}