/*
 * Created on Tue Sep 15 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

import java.util.*;

import java.io.*;

class GropAnagrams {

    public void groupAnagrams(final String[] words) {

        final HashMap<String, ArrayList<String>> m = new HashMap<String, ArrayList<String>>();
        String sorted_word;
        char[] arr;
        for (final String word : words) {
            arr = word.toCharArray();
            Arrays.sort(arr);
            sorted_word = new String(arr);

            if (m.get(sorted_word) == null) {
                m.put(sorted_word, new ArrayList<String>());
            }

            m.get(sorted_word).add(word);

        }

        System.out.println(m.values());

    }

    public static void main(final String[] args) {

        String[] words = { "abc", "dabd", "bca", "cab", "ddba" };
        new GropAnagrams().groupAnagrams(words);

    }
}
