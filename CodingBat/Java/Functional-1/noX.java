public List<String> noX(List<String> strings) {
 strings.replaceAll(s -> s.replaceAll("x", ""));
 return strings;
}
