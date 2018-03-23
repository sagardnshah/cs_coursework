import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.layout.*;
import javafx.scene.shape.Circle;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.text.*;
import javafx.scene.control.*;
import javafx.geometry.Pos;

public class Window extends Application{
	
	public void start(Stage primaryStage) {
		GridPane pane = new GridPane(); // Creates GridPane layout
		pane.setAlignment(Pos.CENTER); // keeps nodes in center
		pane.setHgap(20); // sets horizontal spacing at 20 pixels
		pane.setVgap(10); // sets vertical spacing at 10 pixels
		
		Circle circ = new Circle();//creates new circle with the following properties
		circ.setCenterX(100);
		circ.setCenterY(100);
		circ.setRadius(50);
		circ.setStroke(Color.BLUE); //set outline to blue
		circ.setFill(Color.YELLOW);	//set inside to yellow
		//pane.getChildren().add(circ); //add the circle to the pane
		pane.add(circ, 2, 2);
		
		Label hello = new Label("Hello World"); //create label and font
		hello.setFont(Font.font("Courier New", FontWeight.BOLD,
		FontPosture.ITALIC, 20));
		//pane.getChildren().add(hello); // add label to pane
		pane.add(hello, 1, 0);
		
		Label fun = new Label("Programming is Fun!"); //create label
		fun.setFont(Font.font("Arial", FontWeight.BOLD, 40)); // add font
		//pane.getChildren().add(fun); // add label to pane
		pane.add(fun, 0, 0);
		
		Scene sceneCirc = new Scene (pane, 200, 200); //add pane to scene
		
		primaryStage.setScene(sceneCirc); //add scene to stage
		primaryStage.setTitle("Circle"); //set stage title to hello
		
		primaryStage.show(); //display the stage
	}
	
	public static void main(String[] args) {
		launch(args);
	}
}
