class Solution {
    public:
        int countCollisions(string directions) {
            directions.erase(directions.begin(),ranges::find_if(directions,
            [](char c){return c != 'L';}));
            directions.erase(find_if(directions.rbegin(),directions.rend(),
            [](char c){return c != 'R';}).base(),directions.end());

            return directions.length() - ranges::count(directions,'S');
        }
    };
