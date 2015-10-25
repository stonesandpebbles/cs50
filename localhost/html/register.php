<?php
// configuration
require("../includes/config.php");
// if form was submitted
if ($_SERVER["REQUEST_METHOD"] == "POST")
{
    //validate submission
    if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
    else if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
    else if (empty($_POST["conformation"]))
        {
            apologize("You must confirm your password.");
        }    
    else if (($_POST["password"] !== $_POST["conformation"]))
        {
            //dump($_POST["password"]);
            //dump("test");
            //dump($_POST["conformation"]);
            apologize("Passwords do not match.");
        }    
    
    //add user to database
    $qreturn = query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)",
          $_POST["username"], crypt($_POST["password"]));
    if($qreturn)
    {
        apologize("Username already exists");
    }
    else
    {
        $rows = query("SELECT LAST_INSERT_ID() AS id");
        $id = $rows[0]["id"];
        $_SESSION["id"] = $id;
        redirect("index.php");
    }
}

else
{
// else render form
render("register_form.php", ["title" => "Register"]);
}
?>

