
import javax.swing.*;

import java.awt.*;
import java.awt.event.*;
import java.io.IOException;

@SuppressWarnings("serial")

public class Command extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Client client;


	class playButtonListener implements ActionListener 
	{

		@Override
		public void actionPerformed(ActionEvent e) 
		{
			String reponse = client.send("Multimedia "+"play "+ textInput.getText()+ " ");
			if(reponse.equals("")) {
				JOptionPane.showMessageDialog(getParent(), "playing...");
			}else {
				JOptionPane.showMessageDialog(getParent(), reponse);
			}
		
		}
		

	}

	class SearchButtonListener implements ActionListener 
	{

		@Override
		public void actionPerformed(ActionEvent e) 
		{
			String reponse = client.send("Multimedia "+"get "+ textInput.getText()+ " ");
			JOptionPane.showMessageDialog(getParent(), reponse);
			
			
		}

	}

	class QuitButtonListener implements ActionListener 
	{

		@Override
		public void actionPerformed(ActionEvent e) 
		{
			System.exit(1);
		}

	}

	private AbstractAction searchButtonAs = new AbstractAction() {
		{   
			putValue(Action.NAME,"Search"); 
		}

		@Override public void actionPerformed( ActionEvent e ) {

			String reponse = client.send("Multimedia "+"get "+ textInput.getText()+ " ");
			JOptionPane.showMessageDialog(getParent(), reponse);
		}
	};

	private AbstractAction playButtonAs = new AbstractAction() {
		{   
			putValue(Action.NAME,"Play");
		}

		@Override public void actionPerformed( ActionEvent e ) {

			String reponse = client.send("Multimedia "+"play "+ textInput.getText()+ " ");
			if(reponse.equals("")) {
				JOptionPane.showMessageDialog(getParent(), "playing...");
			}else {
				JOptionPane.showMessageDialog(getParent(), reponse);
			}
		}
	};

	private AbstractAction quitButtonsAs = new AbstractAction() {
		{   
			putValue(Action.NAME,"Quit");
		}

		@Override public void actionPerformed( ActionEvent e ) {
			System.exit(1);
		}
	};

	private JButton searchButton;
	
	private JButton playButton;
	
	private JButton quitButton;
	
	private JTextArea textInput = new JTextArea(5,5);
	
	private JPanel buttonsPanel = new JPanel();

	public Command () 	
	{

		this.buttonsPanel.add(searchButton = new JButton("Search"));

		this.buttonsPanel.add(playButton = new JButton ("Play"));

		this.buttonsPanel.add(quitButton = new JButton("Quit"));

		this.searchButton.addActionListener(new SearchButtonListener());

		this.playButton.addActionListener(new playButtonListener());

		this.quitButton.addActionListener(new QuitButtonListener());

		this.textInput.setLineWrap(true);
		
		this.setJMenuBar(createJMenuBar());
		
		JPanel contentPane = (JPanel) getContentPane();
		
		contentPane.add(createJToolBar(), BorderLayout.NORTH);

		add(new JScrollPane(textInput),BorderLayout.CENTER);

		add (buttonsPanel,BorderLayout.SOUTH);

		setDefaultCloseOperation(EXIT_ON_CLOSE);

		pack();

		setVisible(true);
		
		try {
			client = new Client(client.DEFAULT_HOST, client.DEFAULT_PORT);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private JMenuBar createJMenuBar() 
	{
		JMenuBar menuBar = new JMenuBar();
		
		JMenu menu = new JMenu("Menu");
		
		menu.addSeparator();
		
		menu.add(searchButtonAs);

		menu.add(playButtonAs);
		
		menu.add(quitButtonsAs);
		
		menuBar.add(menu);
		
		return menuBar;
	}
	
	private JToolBar createJToolBar () 
	{
		JToolBar toolBar = new JToolBar();

		toolBar.add(searchButtonAs);
		
		toolBar.add(playButtonAs);
		
		toolBar.add(quitButtonsAs);	
		
		return toolBar;
	}


}
