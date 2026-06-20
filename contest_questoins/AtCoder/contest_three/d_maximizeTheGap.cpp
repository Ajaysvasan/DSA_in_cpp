// Problem Statement
// The country of AtCoder has
// N cities and
// M roads. The
// i-th road
// (1≤i≤M) connects cities
// u
// i
// ​
//   and
// v
// i
// ​
//   bidirectionally, and allows travel from one to the other in
// T
// i
// ​
//   minutes.

// Additionally, each city has a warp gate installed, and you can travel from
// city i (1≤i≤N) to city j (1≤j≤N) using the warp gate in
// X
// i
// ​
//  +X
// j
// ​
//  +Y minutes.

// There are no other ways to travel between cities in the country.

// For each
// k=2,3,…,N, solve the following problem:

// Find the minimum time required to travel from city
// 1 to city
// k.
// The time required to transfer from a road or warp gate to another road or
// warp gate at the same city is negligible.

// Constraints
// 2≤N≤2×10
// 5
//
// 0≤M≤2×10
// 5
//
// 1≤u
// i
// ​
//  <v
// i
// ​
//  ≤N (1≤i≤M)
// 1≤T
// i
// ​
//  ≤10
// 9
//   (1≤i≤M)
// 1≤X
// i
// ​
//  ≤10
// 9
//   (1≤i≤N)
// 1≤Y≤10
// 9
//
// All input values are integers.
// Input
// The input is given from Standard Input in the following format:

// N
// M
// Y
// u
// 1
// ​
//
// v
// 1
// ​
//
// T
// 1
// ​
//
// u
// 2
// ​
//
// v
// 2
// ​
//
// T
// 2
// ​
//
// ⋮
// u
// M
// ​
//
// v
// M
// ​
//
// T
// M
// ​
//
// X
// 1
// ​
//
// X
// 2
// ​
//
// …
// X
// N
// ​
//
// Output
// Output the answers to the problems for
// k=2,3,…,N in this order, separated by spaces.

// Sample Input 1
// Copy
// 7 7 3
// 1 2 1
// 1 3 6
// 2 3 4
// 3 5 8
// 3 7 4
// 4 5 2
// 4 7 9
// 3 1 4 1 5 9 2
// Sample Output 1
// Copy
// 1 5 6 8 14 7
// For example, you can travel from city
// 1 to city
// 7 in
// 7 minutes as follows:

// Use the first road to travel from city
// 1 to city
// 2 in
// 1 minute.
// Use the warp gate to travel from city
// 2 to city
// 7 in
// 1+2+3=6 minutes.
// It is impossible to travel from city
// 1 to city
// 7 in
// 6 minutes or less, so the answer for
// k=7 is
// 7.

// Sample Input 2
// Copy
// 2 0 1000000000
// 1000000000 1000000000
// Sample Output 2
// Copy
// 3000000000
// Note that the answer may be
// 2
// 31
//   or greater.

// Sample Input 3
// Copy
// 12 20 873
// 2 7 940
// 6 9 444
// 6 11 809
// 7 8 786
// 9 10 468
// 7 10 234
// 6 10 660
// 4 12 939
// 8 10 896
// 1 11 953
// 8 10 818
// 4 8 967
// 3 9 724
// 6 7 929
// 3 4 948
// 1 3 999
// 10 11 724
// 7 10 338
// 1 8 967
// 1 12 733
// 581 978 950 629 583 729 554 712 438 930 774 279
// Sample Output 3
// Copy
// 2432 999 1672 2037 1762 1753 967 1723 1677 953 733
