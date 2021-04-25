public int average(int[] scores, int start, int end) {
  int sum = 0;
  for (int i = start; i < end; i++) {
    sum += scores[i];
  }
  return sum / (end - start);
}

public int scoresAverage(int[] scores) {
  return Math.max(average(scores, 0, scores.length / 2), 
                  average(scores, scores.length / 2, scores.length));
}
