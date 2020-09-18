/*
 * Created on Fri Sep 18 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

//  https://users.scala-lang.org/t/solved-how-to-use-variables-in-overriden-method-is-that-possible/6638?u=saireddyavs

object hello {
  def main(Args: Array[String]): Unit = {}

  def moveAllOccurancestoEnd(numbers: Array[Int], number: Int) = {

    implicit val order = new Ordering[Int] {
      override def compare(x: Int, y: Int): Int =
        (x, y) match {

          case (`number`, _) => 1
          case (_, `number`) => -1
          case _             => 0

        }
    }

    println(numbers.mkString(" "))

    numbers.sortInPlace

    // println(numbers.mkString(" "))

  }

  var res = moveAllOccurancestoEnd(
    Array(1, 2, 3, 1, 4, 1, 3, 4, 2, 4, 5, 6, 2, 3, 1),
    1
  )

  println(res)

}
