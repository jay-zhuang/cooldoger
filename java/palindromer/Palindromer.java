public class Palindromer {
    /* Extract the first word that is a palindrom */
    public static String findFirstPalindrom(String input)
    {
        if (input == null || input.length() == 0) return null;

        String[] words = input.split("[^\\w']+");

        for (String word : words) {
            if (word.length() == 0) continue;
            boolean found = false;
            for (int i = 0, j = word.length() - 1; j >= i; i++, j--) {
                found = true;
                if (word.charAt(i) != word.charAt(j)) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return word;
            }
        }
        return null;
    }

    public static void main(String[] args) {
        String[][] testCases = {
            {"Hello mom and dad, how is it going?", "mom"},
            {null, null},
            {"dd", "dd"},
            {"a", "a"},
            {" asdf", null},
            {"asd,as asdf,aa", "aa"},
            {"   asdf,asdf", null},
            {"##  #asa", "asa"},
            {"##  #asd", null},
            {"la $, asd", null},
            {"la $, aa", "aa"},
            {"asdf ai    cwcaacwc aa", "cwcaacwc"},
            {"hello Mom, dad", "dad"},
            {"$#$ add$dda", null},
            {"  aadd, ddaa, bb$#@", "bb"},
        };

        for (String[] testCase : testCases) {
            String result = findFirstPalindrom(testCase[0]);

            System.out.println(testCase[0] + " -> " + testCase[1] + " : " + result);
            if (testCase[1] == null) {
                assert result == null : testCase[0] + " Expect: null" + " Actual: " + result;
            } else {
                assert testCase[1].equals(result) : testCase[0] + " Expect: " + testCase[1] + "Actual: " + result;
            }
        }
    }
};
