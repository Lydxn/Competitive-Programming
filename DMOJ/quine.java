package DMOJ;

public class Quine { public static void main(String[] args) { String quine = "public class Quine { public static void main(String[] args) { String quine = %c%s%c; System.out.printf(quine, 34, quine, 34); } }"; System.out.printf(quine, 34, quine, 34); } }