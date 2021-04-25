public List<String> addStar(List<String> strings) {
  strings.replaceAll(s -> s + "*");
  return strings;
}
