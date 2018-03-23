import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

import javax.swing.*;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;


/**
 * Created by Sagar on Aug 03.
 */
public class Catering extends Application{
    public void start(Stage primaryStage){
        //gridpane
        GridPane pane = new GridPane();
        pane.setAlignment(Pos.TOP_CENTER);
        pane.setHgap(20);
        pane.setVgap(10);

        //button
        Button btSubmit = new Button("Submit");
        btSubmit.setPrefWidth(150);

        //text fields
        TextField tfCustomerName = new TextField();
        TextField tfCustomerPhoneNum = new TextField();
        TextField tfNumOfGuests = new TextField();
        TextField tfCost = new TextField("Cost: ");
        tfCost.setEditable(false);
        //text fields width
        tfCustomerName.setPrefWidth(150);
        tfCustomerPhoneNum.setPrefWidth(150);
        tfNumOfGuests.setPrefWidth(150);
        tfCost.setPrefWidth(150);
        //text field alignment
        tfCustomerName.setAlignment(Pos.BOTTOM_RIGHT);
        tfCustomerPhoneNum.setAlignment(Pos.BOTTOM_RIGHT);
        tfNumOfGuests.setAlignment(Pos.BOTTOM_RIGHT);
        tfCost.setAlignment(Pos.BOTTOM_LEFT);

        //combo box - Entree
        ComboBox<String> cbEntreeChoices = new ComboBox<>();
        cbEntreeChoices.setEditable(false);
        cbEntreeChoices.getItems().addAll("Choice 1", "Choice 2", "Choice 3", "Choice 4");
        cbEntreeChoices.setPrefWidth(150);

        //combo box - Desert
        ComboBox <String> cbDesertChoices = new ComboBox<>();
        cbDesertChoices.setEditable(false);
        cbDesertChoices.getItems().addAll("Choice 1", "Choice 2", "Choice 3");
        cbDesertChoices.setPrefWidth(150);

        //check boxes
        CheckBox ckChoice1 = new CheckBox("Choice 1");
        CheckBox ckChoice2 = new CheckBox("Choice 2");
        CheckBox ckChoice3 = new CheckBox("Choice 3");
        CheckBox ckChoice4 = new CheckBox("Choice 4");

        //labels
        Label lbCustomerName = new Label("Customer Name");
        Label lbCustomerPhoneNum = new Label("Customer Phone Number");
        Label lbNumOfGuests = new Label("Number of Guests");
        Label lbEntree = new Label("Entree");
        Label lbSideDish = new Label("Side Dishes (2)");
        Label lbDesert = new Label("Desert");

        //adding nodes to the grid layout
        pane.add(lbCustomerName, 0, 1);
        pane.add(tfCustomerName, 1,1, 2, 1);
        pane.add(lbCustomerPhoneNum, 0, 2);
        pane.add(tfCustomerPhoneNum, 1, 2, 2, 1);
        pane.add(lbNumOfGuests, 0,3);
        pane.add(tfNumOfGuests, 1, 3, 2, 1);
        pane.add(lbEntree, 0, 4);
        pane.add(cbEntreeChoices, 1, 4, 2, 1);
        pane.add(lbSideDish, 0, 5);
        pane.add(ckChoice1, 1, 5);
        pane.add(ckChoice2, 2,5);
        pane.add(ckChoice3, 1, 6);
        pane.add(ckChoice4, 2, 6);
        pane.add(lbDesert, 0, 7);
        pane.add(cbDesertChoices, 1, 7, 2, 1);
        pane.add(btSubmit, 1, 9, 2, 1);
        pane.add(tfCost, 0, 9);

        Scene scene = new Scene(pane, 350,300);

        primaryStage.setScene(scene);
        primaryStage.setTitle("Cindy's Catering");
        primaryStage.show();

        btSubmit.setOnAction(e -> {
            //variables
            String  name = tfCustomerName.getText();
            String phoneNum = tfCustomerPhoneNum.getText();
            Integer numOfGuests = null;
            String entree = cbEntreeChoices.getValue();;
            String sideDishes = "";
            String desert = cbDesertChoices.getValue();
            Integer cost = null;
            //number of people & cost
            try{
                numOfGuests = Integer.parseInt(tfNumOfGuests.getText());
                cost = 35 * numOfGuests;
            }
            catch(NumberFormatException ex){
                numOfGuests = 0;
                cost = 0;
            }
            tfCost.setText("Cost: $" + Double.toString(cost));

            //sidedishes
            Integer numOfSideDish = 0;
            if(ckChoice1.isSelected()) {
                numOfSideDish++;
                sideDishes = ckChoice1.getText() + " ";
            }
            if(ckChoice2.isSelected()) {
                numOfSideDish++;
                sideDishes += ckChoice2.getText()  + " ";
            }
            if(ckChoice3.isSelected()) {
                numOfSideDish++;
                sideDishes += ckChoice3.getText()  + " ";
            }
            if(ckChoice4.isSelected()) {
                numOfSideDish++;
                sideDishes += ckChoice4.getText()  + " ";
            }

            if(numOfSideDish > 2){
                ckChoice1.setSelected(false);
                ckChoice2.setSelected(false);
                ckChoice3.setSelected(false);
                ckChoice4.setSelected(false);
                JOptionPane.showMessageDialog(null, "Try Again! Only 2 side dishes allowed.");
            }


            //handle empty items
            if(name == null || name.trim().isEmpty())
                name = "None";
            if(phoneNum == null || phoneNum.trim().isEmpty())
                phoneNum = "None";
            if(entree == null || entree.trim().isEmpty())
                entree = "None";
            if(sideDishes == null || sideDishes.trim().isEmpty())
                sideDishes = "None";
            if(desert == null || desert.trim().isEmpty())
                desert = "None";

            //only write to file if num of side dishes is less than 3
            if(numOfSideDish<3){
                FileWriter fw = null;
                BufferedWriter bw = null;

                try{
                    fw = new FileWriter("Event.txt");
                    bw = new BufferedWriter(fw);
                    bw.write("Customer Name: " + name + ". \n");
                    bw.write("Customer Phone Number: " + phoneNum + ". \n");
                    bw.write("Number of Guests: " + numOfGuests + ". \n");
                    bw.write("Entree: " + entree + ". \n");
                    bw.write("Side Dishes: " + sideDishes.trim() + ". \n");
                    bw.write("Dessert: " + desert + ". \n");
                    bw.write("Cost: $" + cost + ". \n");
                    bw.close();
                } catch (IOException e1) {
                    e1.printStackTrace();
                }
            }

        });
    }
    public static void main(String[] args){
        launch(args);
    }
}
