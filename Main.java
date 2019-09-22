package Polynomial;

import java.io.FileNotFoundException;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;

public class Main extends Application
{
	@Override
	public void start(Stage primaryStage) throws Exception
	{
		Parent root = FXMLLoader.load(getClass().getResource("UI.fxml"));

		primaryStage.getIcons().add(new Image("file:icon.png"));
		primaryStage.setTitle("Polynomial Operations");
		primaryStage.setScene(new Scene(root));
		primaryStage.setResizable(false);

		primaryStage.show();
	}

	public static void main(String[] args) throws FileNotFoundException
	{
		launch(args);
	}
}
