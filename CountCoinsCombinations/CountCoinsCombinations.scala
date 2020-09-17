object hello {
  def main(Args: Array[String]): Unit = {

    def iterative(coins: List[Int], number: Int): Int = {
      if (number < 0 || coins.isEmpty) 0
      else if (number == 0) 1
      else
        iterative(coins.tail, number) + iterative(
          coins,
          number - coins.head
        )
    }

    println(iterative(List(1, 2, 4), 6))

    println(iterative(List(1, 2, 3), 4))
  }

}
