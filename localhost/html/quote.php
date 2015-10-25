<?php
    //config
require("../includes/config.php");
if ($_SERVER["REQUEST_METHOD"] == "POST")
{
    //no value entered
    if(empty($_POST["symbol"]))
    {
        apologize("Please enter a stock symbol");
    }
    //invalid symbol entered
    else if (($squery = lookup($_POST["symbol"])) === false)
    {
        apologize("Enter a valid stock symbol");
    }
    //display the stock price
    else
    {
        render("quote_result.php",['title'=>'Quote Price', 'result'=>$squery]);
    }
}

//display quote form
else
{
    render("quote_form.php", ['title'=>'Enter Symbol']);
}
