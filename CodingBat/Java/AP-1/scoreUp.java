public int scoreUp(String[] key, String[] answers) {
  int score = 0;
  for (int i = 0; i < key.length; i++) {
    if (key[i].equals(answers[i]))
      score += 4;
    else if (!answers[i].equals("?") && !key[i].equals(answers[i]))
      score--;
  }
  return score;
}
