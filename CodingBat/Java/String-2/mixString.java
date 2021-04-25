public String mixString(String a, String b) {
  int min = Math.min(a.length(),b.length());
  String mix = "";
  for (int i = 0; i < min; i++) {
    mix = mix + a.charAt(i) + b.charAt(i);
  }
  return mix += b.substring(min) + a.substring(min);
}
