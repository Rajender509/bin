import 'package:flutter/material.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text("Column Example"),
        ),
        body: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly, // Space evenly between children
          children: <Widget>[
            Container(
              margin: EdgeInsets.all(12.0), // Margin around the container
              padding: EdgeInsets.all(20.0), // Padding inside the container
              decoration: BoxDecoration(
                borderRadius: BorderRadius.circular(8), // Rounded corners
                color: Colors.red, // Background color
              ),
              child: Text(
                "Android",
                style: TextStyle(color: Colors.white, fontSize: 25), // Text style
              ),
            ),
            Container(
              margin: EdgeInsets.all(12.0),
              padding: EdgeInsets.all(20.0),
              decoration: BoxDecoration(
                borderRadius: BorderRadius.circular(8),
                color: Colors.green,
              ),
              child: Text(
                "iOS",
                style: TextStyle(color: Colors.white, fontSize: 25),
              ),
            ),
            Container(
              margin: EdgeInsets.all(12.0),
              padding: EdgeInsets.all(20.0),
              decoration: BoxDecoration(
                borderRadius: BorderRadius.circular(8),
                color: Colors.blue,
              ),
              child: Text(
                "Web",
                style: TextStyle(color: Colors.white, fontSize: 25),
              ),
            ),
          ],
        ),
      ),
    );
  }
}

cont
import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text("Flutter Container Example"),
        ),
        body: Container(
          padding: EdgeInsets.all(35), // Padding inside the container
          margin: EdgeInsets.all(20), // Margin outside the container
          decoration: BoxDecoration(
            border: Border.all(color: Colors.black, width: 4), // Black border
            borderRadius: BorderRadius.circular(8), // Rounded corners
            boxShadow: [
              BoxShadow(
                color: Colors.green, // Shadow color
                offset: Offset(6.0, 6.0), // Shadow offset
              ),
            ],
          ),
          child: Text(
            "Hello! I am in the container widget!",
            style: TextStyle(fontSize: 30), // Text style
          ),
        ),
      ),
    );
  }
}
