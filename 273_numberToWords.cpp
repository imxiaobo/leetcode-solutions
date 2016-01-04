class Solution {
public:
  string numberToWords(int num) {

    if (num == 0)
      return "Zero";

    static string D[] = {"", "Thousand", "Million", "Billion"};

    string result;
    int i = 0;
    while (num) {
      int parts = num % 1000;
      string s = threeDigitNumberToWords(parts);
      if (!s.empty()) {
        if (i != 0) {
          result = s + " " + D[i] + (result.empty() ? "" : " " + result);
        } else
          result = s;
      }
      ++i;
      num /= 1000;
    }
    return result;
  }

  // non-zero
  string threeDigitNumberToWords(int num) {
    static string A[20] = {
        "",        "One",     "Two",       "Three",    "Four",
        "Five",    "Six",     "Seven",     "Eight",    "Nine",
        "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
    };

    static string B[10] = {"",      "",      "Twenty",  "Thirty", "Forty",
                           "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    static string C[10] = {
        "", "One Hundred", "Two Hundred", "Three Hundred", "Four Hundred",
        "Five Hundred", "Six Hundred", "Seven Hundred", "Eight Hundred",
        "Nine Hundred",
    };

    if (num < 20)
      return A[num];
    else {
      int hundreds = num / 100;
      int tens = num - hundreds * 100;

      string result;
      if (hundreds > 0)
        result += C[hundreds];

      if (tens == 0)
        return result;

      else if (tens < 20) {
        result += (result.empty() ? "" : " ") + A[tens];
        return result;
      } else {
        int ones = tens % 10;
        result += (result.empty() ? "" : " ") + B[tens / 10];
        if (ones == 0)
          return result;
        else {

          result += (result.empty() ? "" : " ") + A[ones];
          return result;
        }
      }
    }
  }
};
