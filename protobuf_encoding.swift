//
//
// Middleware.playground
//
// Created by Konstantin Kuchenmeister on 13.02.2020
//


import Foundation
import PlaygroundSupport


/// @Param:
/// Number: The number to be encoded
/// Size: The bitcount of the number
/// Type: Whether zigzag encoding should take place or not
let number: Int = -2184
let size: Int = 16
let type: Bool = true


func zigZag() -> Int {
    return (number >> (size-1)) ^ (number << 1)
}
print("ZigZag-Result: " + String(zigZag(), radix: 2))


// MARK: - Variable length encoding. Takes a zigzag encoded number as input. Not the best solution but should currently work until (including) Int16. Will probably convert to an array for anything larger.
func vle() -> String {
    var repr: String
    if type {
        repr = String(zigZag(), radix: 2)
    } else {
        repr = String(number, radix: 2)
    }
    if repr.count < 8 {
        return pad(string: repr, toSize: 8)
    } else if repr.count < 16 {
        let start = pad(string: repr, toSize: 16)
        print("VLE-Start: " + start)
        let iteration1 = "(1)" + start.suffix(7)
        var second = start.prefix(9)
        second.remove(at: second.startIndex)
        second.remove(at: second.index(after: second.startIndex))
        let iteration2 = "(0)" + second
        return iteration1 + " " + iteration2
    } else {
        return "This bit-size is not supported"
    }
}


// MARK: - Pads the binary representation of the number with the wanted amount of zeros
func pad(string : String, toSize: Int) -> String {
    var padded = string
    for _ in 0..<(toSize - string.count) {
        padded = "0" + padded
    }
    return padded
}
func protobuf() -> String{
    vle()
}


print("VLE-Result: " + protobuf())
