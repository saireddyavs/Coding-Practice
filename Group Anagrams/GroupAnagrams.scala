/*
 * Created on Tue Sep 15 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

object groupAnagrams{
    def main(Args:Array[String]){
        var words= Array("abc", "dabd", "bca", "cab", "ddba" )

        var res=words.groupBy(word=>word.sorted).values.map(_.toList)

        println(res.mkString(" "))


    }
}