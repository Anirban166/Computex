package Polynomial;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;
import java.util.Scanner;
import Structures.CharsLinkedList;
import Structures.LinkedList;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.*;


public class Controller implements Initializable
{
	@FXML
	private ListView<LinkedList> list;
	@FXML
	private ChoiceBox<LinkedList> poly1;
	@FXML
	private ChoiceBox<LinkedList> poly2;
	@FXML
	private ChoiceBox<Character> op;
	@FXML
	private Button calc, sub, addAll, subAll, mulAll, sub2;
	@FXML
	private TextField res1, res2, res3, res4, x, x2;

	private ArrayList<LinkedList> lists;
	private LinkedList result, result2;

	// A method that initializes the needed UI components
	@Override
	public void initialize(URL location, ResourceBundle resources)
	{
		lists = readPolys();
		ObservableList<LinkedList> polysList = FXCollections.observableArrayList(lists);
		poly1.setItems(polysList);
		poly2.setItems(polysList);
		list.setItems(polysList);

		ObservableList<Character> ops = FXCollections.observableArrayList();
		ops.add('+');
		ops.add('-');
		ops.add('*');
		op.setItems(ops);

		// If the file is empty
		if(lists.size() == 0)
		{
			calc.setDisable(true);
			sub.setDisable(true);
			addAll.setDisable(true);
			subAll.setDisable(true);
			mulAll.setDisable(true);
			sub2.setDisable(true);
			res1.setText("--> No polynomials in the file !");
			res3.setText("--> No polynomials in the file !");
		}
	}

	// A method that gets the selected operation and executes it on the chosen polynomials
	public void calculate()
	{
		try
		{
			switch (op.getSelectionModel().getSelectedItem())
			{
			case '+':
				result = PolynomialOperations.add(poly1.getSelectionModel().getSelectedItem().getFirst(), poly2.getSelectionModel().getSelectedItem().getFirst());
				break;
			case '-':
				result = PolynomialOperations.subtract(poly1.getSelectionModel().getSelectedItem().getFirst(), poly2.getSelectionModel().getSelectedItem().getFirst());
				break;
			case '*':
				result = PolynomialOperations.multiply(poly1.getSelectionModel().getSelectedItem().getFirst(), poly2.getSelectionModel().getSelectedItem().getFirst());
			}
			if(!result.toString().equals("") && !result.toString().equals(" + "))
				res1.setText(result.toString());
			else
				res1.setText(0 + "");
		}
		catch (java.lang.NullPointerException ex)
		{
			res1.setText("Choose two available polynomials and an operation please !");
		}
	}

	// A method that gets the X's value and calls the right method to substitute it
	public void substitute()
	{
		if(result != null)
		{
			try
			{
				if(!x.getText().equals(""))
					res2.setText(PolynomialOperations.substitute(result.getFirst(), Double.parseDouble(x.getText().trim())) + "");
				else
					res2.setText("Enter X's value please !");
			}
			catch (java.lang.NumberFormatException ex)
			{
				res2.setText("X must be a number !");
			}
		}
		else
			res2.setText("No result polynomial !");
	}

	// A method that calls the right method to add all the polynomials
	public void addAll()
	{
		result2 = PolynomialOperations.add(lists);
		res3.setText(result2.toString());
	}

	// A method that calls the right method to subtract all the polynomials
	public void subtractAll()
	{
		result2 = PolynomialOperations.subtract(lists);
		res3.setText(result2.toString());
	}

	// A method that calls the right method to multiply all the polynomials
	public void multiplyAll()
	{
		result2 = PolynomialOperations.multiply(lists);
		res3.setText(result2.toString());
	}

	// A method that gets the X's value and calls the right method to substitute it in All
	public void substituteInAll()
	{
		if(result2 != null)
		{
			try
			{
				if(!x2.getText().equals(""))
					res4.setText(PolynomialOperations.substitute(result2.getFirst(), Double.parseDouble(x2.getText().trim())) + "");
				else
					res4.setText("Enter X's value please !");
			}
			catch (java.lang.NumberFormatException ex)
			{
				res4.setText("X must be a number !");
			}
		}
		else
			res4.setText("No result polynomial !");
	}

	// A method that reads the polynomials from the file
	public ArrayList<LinkedList> readPolys()
	{
		ArrayList<LinkedList> polys = new ArrayList<>();

		File file = new File("polys.txt");

		Scanner input = null;

		try
		{
			input = new Scanner(file);

			while(input.hasNextLine())
			{
				String str = input.nextLine();
				String[] data = str.split("[ ]+");

				if(data.length == 1 && data[0].length() == 0)
					continue;

				if(data.length == 1 && (str.lastIndexOf('+') > 0 || str.lastIndexOf('-') > 0))
				{
					CharsLinkedList chars = new CharsLinkedList();

					for(int i = 0; i < str.length(); i++)
					{
						if((str.charAt(i) == '+' || str.charAt(i) == '-') && i != 0 && i != str.length() - 1)
						{
							chars.insert(' ');
							chars.insert(str.charAt(i));
							chars.insert(' ');
						}
						else
							chars.insert(str.charAt(i));

					}

					str = chars.toString();
					data = str.split("[ ]+");
				}

				polys.add(new LinkedList());

				for (int i = 0; i < data.length; i += 2)
				{
					if(i > 0)
					{
						if(data[i - 1].equals("+"))
						{
							if(data[i].indexOf('x') != -1)
							{
								if(data[i].indexOf('^') != -1)
								{
									if(data[i].charAt(0) == 'x')
										polys.get(polys.size() - 1).insertSorted(1, Integer.parseInt(data[i].substring(data[i].indexOf('^') + 1, data[i].length())));
									else
										polys.get(polys.size() - 1).insertSorted(Double.parseDouble(data[i].substring(0, data[i].indexOf('x'))), Integer.parseInt(data[i].substring(data[i].indexOf('^') + 1, data[i].length())));

								}
								else
								{
									if(data[i].charAt(0) == 'x')
										polys.get(polys.size() - 1).insertSorted(1, 1);
									else
										polys.get(polys.size() - 1).insertSorted(Double.parseDouble(data[i].substring(0, data[i].indexOf('x'))), 1);
								}
							}
							else
								polys.get(polys.size() - 1).insertSorted(Double.parseDouble(data[i]), 0);
						}
						else if(data[i - 1].equals("-"))
						{
							if(data[i].indexOf('x') != -1)
							{
								if(data[i].indexOf('^') != -1)
								{
									if(data[i].charAt(0) == 'x')
										polys.get(polys.size() - 1).insertSorted(-1, Integer.parseInt(data[i].substring(data[i].indexOf('^') + 1, data[i].length())));
									else
										polys.get(polys.size() - 1).insertSorted(-1 * Double.parseDouble(data[i].substring(0, data[i].indexOf('x'))), Integer.parseInt(data[i].substring(data[i].indexOf('^') + 1, data[i].length())));
								}
								else
								{
									if(data[i].charAt(0) == 'x')
										polys.get(polys.size() - 1).insertSorted(-1, 1);
									else
										polys.get(polys.size() - 1).insertSorted(-1 * Double.parseDouble(data[i].substring(0, data[i].indexOf('x'))), 1);
								}
							}
							else
								polys.get(polys.size() - 1).insertSorted(-1 * Double.parseDouble(data[i]), 0);
						}
					}
					else
					{
						if(data[i].indexOf('x') != -1)
						{
							if(data[i].indexOf('^') != -1)
							{
								if(data[i].charAt(0) == 'x')
									polys.get(polys.size() - 1).insertSorted(1, Integer.parseInt(data[i].substring(data[i].indexOf('^') + 1, data[i].length())));
								else if(data[i].charAt(0) == '-' && data[i].charAt(1) == 'x')
									polys.get(polys.size() - 1).insertSorted(-1, Integer.parseInt(data[i].substring(data[i].indexOf('^') + 1, data[i].length())));
								else
									polys.get(polys.size() - 1).insertSorted(Double.parseDouble(data[i].substring(0, data[i].indexOf('x'))), Integer.parseInt(data[i].substring(data[i].indexOf('^') + 1, data[i].length())));
							}
							else
							{
								if(data[i].charAt(0) == 'x')
									polys.get(polys.size() - 1).insertSorted(1, 1);
								else if(data[i].charAt(0) == '-' && data[i].charAt(1) == 'x')
									polys.get(polys.size() - 1).insertSorted(-1, 1);
								else
									polys.get(polys.size() - 1).insertSorted(Double.parseDouble(data[i].substring(0, data[i].indexOf('x'))), 1);
							}
						}
						else
							polys.get(polys.size() - 1).insertSorted(Double.parseDouble(data[i]), 0);
					}
				}

				if(polys.get(polys.size() - 1).size() == 1 && polys.get(polys.size() - 1).getFirst().getCoefficient() == 0)
					polys.remove(polys.size() - 1);

			}

			input.close();
		}

		// Catches if the file is not found
		catch (FileNotFoundException ex1)
		{
			calc.setDisable(true);
			sub.setDisable(true);
			addAll.setDisable(true);
			subAll.setDisable(true);
			mulAll.setDisable(true);
			sub2.setDisable(true);
			res1.setText("--> ERROR: File doesn't exist!!");
			res3.setText("--> ERROR: File doesn't exist!!");
		}

		return polys;
	}

	// A method that exits the program
	public void exit()
	{
		System.exit(0);
	}
}
