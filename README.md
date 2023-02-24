# GoStrings
C package designed to be similar to GO's strings library


## Compiling
```
gcc gostrings.c <filename>.c
```

## Documentation
https://github.com/JewishLewish/GoStrings/wiki/Documentation


## Progress
| Syntax | Description | Progress |
| --- | --- | :---: |
| Clone | Returns a Fresh Copy of a Certain String | ✔️ |
| Compare | Compare returns an integer comparing two strings lexicographically. The result will be 0 if a == b, -1 if a < b, and +1 if a > b. | ✔️ |
| Contains | Contains reports whether substr is within s. | ✔️ |
| ContainsAny| ContainsAny reports whether any Unicode code points in chars are within s. <br> ``Contains can be used``| ⬆️ |
| ContainsRunes | ContainsRune reports whether the Unicode code point r is within s. <br> ``Contains can be used`` | ⬆️ |
| Count | Count counts the number of non-overlapping instances of substr in s. If substr is an empty string, Count returns 1 + the number of Unicode code points in s.| ✔️ |
| Cut | Cut slices s around the first instance of sep, returning the text before and after sep. The found result reports whether sep appears in s. If sep does not appear in s, cut returns s, "", false. | ✔️ |
| CutPrefix | CutPrefix returns s without the provided leading prefix string and reports whether it found the prefix. If s doesn't start with prefix, CutPrefix returns s, false. If prefix is the empty string, CutPrefix returns s, true. | ✔️ |
| CutSuffix | CutSuffix returns s without the provided ending suffix string and reports whether it found the suffix. If s doesn't end with suffix, CutSuffix returns s, false. If suffix is the empty string, CutSuffix returns s, true. | ✔️ |
| EqualsFold | EqualFold reports whether s and t, interpreted as UTF-8 strings, are equal under simple Unicode case-folding, which is a more general form of case-insensitivity. | ✔️ |
| Fields | Fields splits the string s around each instance of one or more consecutive white space characters, as defined by unicode.IsSpace, returning a slice of substrings of s or an empty slice if s contains only white space. | ✔️ |
| FieldsFunc | FieldsFunc splits the string s at each run of Unicode code points c satisfying f(c) and returns an array of slices of s. If all code points in s satisfy f(c) or the string is empty, an empty slice is returned. <br> ``Nested Functions Cannot be Done in C ``| 🛑 |
| HasPrefix | HasPrefix tests whether the string s begins with prefix. | ✔️ |
| HasSuffix | HasSuffix tests whether the string s ends with suffix. | ✔️ |
| Index | Index returns the index of the first instance of substr in s, or -1 if substr is not present in s. | ✔️ |
| IndexAny | IndexAny returns the index of the first instance of any Unicode code point from chars in s, or -1 if no Unicode code point from chars is present in s. <br> ``You Can Use Index`` | ⬆️ |
| IndexByte | IndexByte returns the index of the first instance of c in s, or -1 if c is not present in s. <br> ``You Can Use Index`` | ⬆️ |
| IndexFunc | IndexFunc returns the index into s of the first Unicode code point satisfying f(c), or -1 if none do. <br> ``Nested Functions Cannot be Done in C ``| 🛑 |
| IndexRune| IndexRune returns the index of the first instance of the Unicode code point r, or -1 if rune is not present in s. If r is utf8.RuneError, it returns the first instance of any invalid UTF-8 byte sequence. <br> ``You Can Use Index`` | ⬆️ |
| Join | Join concatenates the elements of its first argument to create a single string. The separator string sep is placed between elements in the resulting string. | ✔️ |
| LastIndex | LastIndex returns the index of the last instance of substr in s, or -1 if substr is not present in s. | ✔️ |
| LastIndexAny | LastIndexAny returns the index of the last instance of any Unicode code point from chars in s, or -1 if no Unicode code point from chars is present in s. <br> ``You Can Use LastIndex`` | ⬆️ |
| LastIndexFunc | LastIndexFunc returns the index into s of the last Unicode code point satisfying f(c), or -1 if none do. <br> ``Nested Functions Cannot be Done in C ``| 🛑 |
| Map | Map returns a copy of the string s with all its characters modified according to the mapping function. If mapping returns a negative value, the character is dropped from the string with no replacement. <br> ``Nested Functions Cannot be Done in C ``| 🛑 |
| Repeat | Repeat returns a new string consisting of count copies of the string s. | ✔️ |
| Replace | Replace returns a copy of the string s with the first n non-overlapping instances of old replaced by new. If old is empty, it matches at the beginning of the string and after each UTF-8 sequence, yielding up to k+1 replacements for a k-rune string. If n < 0, there is no limit on the number of replacements. | ✔️ |
| ReplaceAll | ReplaceAll returns a copy of the string s with all non-overlapping instances of old replaced by new. If old is empty, it matches at the beginning of the string and after each UTF-8 sequence, yielding up to k+1 replacements for a k-rune string. | ✔️ |
| Split | Split slices s into all substrings separated by sep and returns a slice of the substrings between those separators. | ✔️ |
| SplitAfter | SplitAfter slices s into all substrings after each instance of sep and returns a slice of those substrings. | ✔️ |
| SplitAfterN | SplitAfterN slices s into substrings after each instance of sep and returns a slice of those substrings. | ✔️ |
| SplitN | SplitN slices s into substrings separated by sep and returns a slice of the substrings between those separators. | ✔️ |
| ToLower | ToLower returns s with all Unicode letters mapped to their lower case. | ✔️ |
| ToLowerSpecial | ToLowerSpecial returns a copy of the string s with all Unicode letters mapped to their lower case using the case mapping specified by c. <br> ``Use ToLower()`` | ⬆️ |
| ToTitle | ToTitle returns a copy of the string s with all Unicode letters mapped to their Unicode title case. | ✔️ |
| ToTitleSpecial | ToTitleSpecial returns a copy of the string s with all Unicode letters mapped to their Unicode title case, giving priority to the special casing rules. <br> ``Use ToTitle()`` | ⬆️ |
| ToUpper | ToUpper returns s with all Unicode letters mapped to their upper case. | ✔️ |
| ToUpperSpecial | ToUpperSpecial returns a copy of the string s with all Unicode letters mapped to their upper case using the case mapping specified by c. <br> ``Use ToUpper()`` | ⬆️ |
| ToValidUTF8 | ToValidUTF8 returns a copy of the string s with each run of invalid UTF-8 byte sequences replaced by the replacement string, which may be empty. <br> ``C will give warning: hex escape sequence out of range`` | ⚠️ |
| Trim | Trim returns a slice of the string s with all leading and trailing Unicode code points contained in cutset removed. | ✔️ |
