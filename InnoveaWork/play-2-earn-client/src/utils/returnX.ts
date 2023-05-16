export const getReturnX = (rank: number) => {
  return rank >= 1 && rank <= 10
    ? "2.5x"
    : rank > 10 && rank <= 20
    ? "2x"
    : "1.5x"
}
