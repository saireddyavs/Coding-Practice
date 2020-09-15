
/*
 * Created on Tue Sep 15 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

object hello{
    def main(Args:Array[String]):Unit={

       

        var result=(arr:Array[Int]) => arr.scanLeft(0)(
            (accumulated_value,number)=> 0 max accumulated_value+number  
        ).max



        var a=Array(8, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 4)

        println(result(a))

        println(result(Array(3, 5, -9, 1, 3, -2, 3, 4, 7, 2, -9, 6, 3, 1, -5, 4)))

        

       

    }
}