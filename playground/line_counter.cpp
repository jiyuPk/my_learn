import std.core;

using namespace std;

int count_lines(const string& filename)
{
    ifstream in(filename);

    return std::count(
        std::istream_iterator<char>(in >> std::noskipws),
        std::istream_iterator<char>(),
        '\n');
}

vector<int> count_lines_in_files(const vector<string>& files)
{
    vector<int> results(files.size());

    std::transform(files.cbegin(), files.cend(), results.begin(), count_lines);

    return results;
}

int main(int argc, char* argv[])
{
    auto results = count_lines_in_files({ "main.cpp"});

    for (const auto& result : results) {
        std::cout << result << " line(s)\n";
    }

    return 0;
}