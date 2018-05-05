val letterToPoints = fn
   "A" => SOME 4.0
 | "B+" => SOME 3.5
 | "B" => SOME 3.0
 | "C+" => SOME 2.5
 | "C" => SOME 2.0
 | "D" => SOME 1.0
 | _ => NONE

fun sumPoints (credits, points, stream) =
   let
      val line = TextIO.inputLine stream
      val tokens = String.tokens Char.isSpace (getOpt (line, ""))
      val c = getOpt (Real.fromString (hd tokens) handle Empty => NONE, 0.0)
      val p = letterToPoints (hd (tl tokens)) handle Empty => NONE
   in
      if not (isSome line)
         then (credits, points)
      else if isSome p
         then sumPoints (credits + c, points + c * (valOf p), stream)
      else sumPoints (credits, points, stream)
   end

fun printGpa (filename) =
   let
      val f = TextIO.openIn filename
      val (c, p) = sumPoints (0.0, 0.0, f)
      val () = TextIO.closeIn f
      val gpa = p / c
   in
      print (concat [filename, ": ", Real.toString c, " credits, ",
                     Real.toString p, " points, average ",
                     Real.toString gpa, "\n"])
   end
   handle Io => print (concat ["could not read ", filename, "\n"])

val () = app printGpa (CommandLine.arguments ())
