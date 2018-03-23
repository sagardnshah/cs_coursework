/**
 * @author Sagar Shah
 */
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.control.*;
import javafx.scene.Scene;
import javafx.scene.layout.GridPane; //adds the GridPane layout
import javafx.geometry.Pos; //allows alignment
import javafx.scene.paint.Color;
import java.lang.Math;

public class Investment extends Application{
	public void start(Stage primaryStage) {
		GridPane pane = new GridPane();		
		pane.setAlignment(Pos.CENTER);
		pane.setVgap(10);
		pane.setHgap(10);
		
		TextField tfInvestment = new TextField();
		TextField tfAnnualIntRate = new TextField();
		TextField tfNumOfYears = new TextField();
		TextField tfFutureVal = new TextField();
		tfFutureVal.setEditable(false);
		
		tfInvestment.setAlignment(Pos.BOTTOM_RIGHT);
		tfAnnualIntRate.setAlignment(Pos.BOTTOM_RIGHT);
		tfNumOfYears.setAlignment(Pos.BOTTOM_RIGHT);
		tfFutureVal.setAlignment(Pos.BOTTOM_RIGHT);
		
		Label lbInvestment = new Label("Investment");
		Label lbAnnualIntRate = new Label("Annual Interest Rate");
		Label lbNumOfYears = new Label("Number of Years");
		Label lbFutureVal = new Label("Future Value");
		
		Button btCalc = new Button("Calculate");
		btCalc.setTextFill(Color.RED);
		
		pane.add(lbInvestment, 0, 0);
		pane.add(tfInvestment, 1, 0);
		pane.add(lbAnnualIntRate, 0, 1);
		pane.add(tfAnnualIntRate, 1, 1);
		pane.add(lbNumOfYears, 0, 2);
		pane.add(tfNumOfYears, 1, 2);
		pane.add(lbFutureVal, 0, 3);
		pane.add(tfFutureVal, 1, 3);
		pane.add(btCalc, 1, 5);
		
		btCalc.setOnAction(e -> {
			double investment = Double.parseDouble(tfInvestment.getText());
			double annualIntRate = Double.parseDouble(tfAnnualIntRate.getText());
			double numOfYears = Double.parseDouble(tfNumOfYears.getText());
			
			double duration = numOfYears * 12;
			double futureVal = Math.floor((investment * Math.pow((1 + annualIntRate / 100), duration)) * 100) / 100;
			tfFutureVal.setText(Double.toString(futureVal));
		});
		
		Scene scene = new Scene(pane, 400, 250);
		
		primaryStage.setTitle("Future Value Calculator");
		primaryStage.setScene(scene);
		
		primaryStage.show();
	}
	
	public static void main(String[] args) {
		launch(args);
	}
}
