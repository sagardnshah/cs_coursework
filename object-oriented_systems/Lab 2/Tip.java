import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.control.*;
import javafx.scene.Scene;
import javafx.scene.layout.GridPane; //adds the GridPane layout
import javafx.geometry.Pos; //allows alignment
import javafx.scene.paint.Color;

public class Tip extends Application{
	@Override // Override the start method in the Application class
	public void start(Stage primaryStage) {
		GridPane tipPane = new GridPane();
		// Position tipPane for center
		tipPane.setAlignment(Pos.CENTER);
		// Set spaces between controls
		tipPane.setVgap(10); // Veritical spacing to 10
		tipPane.setHgap(5); // Horizontal spacing to 5
		
		TextField tfCheck = new TextField();
		TextField tfPercent = new TextField();
		TextField tfTotal = new TextField();
		tfTotal.setEditable(false);
		
		tfCheck.setAlignment(Pos.BOTTOM_RIGHT);
		tfPercent.setAlignment(Pos.BOTTOM_RIGHT);
		tfTotal.setAlignment(Pos.BOTTOM_RIGHT);
		
		Label lbCheck = new Label("Check Amount");
		Label lbPercent = new Label("Tip Percent");
		Label lbTotal = new Label("Total Amount");
		
		Button btCalc = new Button("Calculate");
		btCalc.setTextFill(Color.RED);
		
		tipPane.add(lbCheck, 0 , 0);
		tipPane.add(tfCheck, 1 , 0);
		tipPane.add(lbPercent, 0 , 1);
		tipPane.add(tfPercent, 1 , 1);
		tipPane.add(lbTotal, 0 , 2);
		tipPane.add(tfTotal, 1 , 2);
		tipPane.add(btCalc, 1 , 4);
		
		btCalc.setOnAction(e -> {
		// Java code to execute when the event is fired
		double check = Double.parseDouble(tfCheck.getText());
		double percent = Double.parseDouble(tfPercent.getText());
		percent = percent / 100;
		double total = check + check * percent;
		tfTotal.setText(Double.toString(total));
		});
		
		Scene tipScene = new Scene(tipPane, 400, 300);
		
		primaryStage.setTitle("Gratuity");
		primaryStage.setScene(tipScene);
		
		primaryStage.show();
	}
	
	public static void main(String[] args) {
		launch(args);
	}
}
