<?php
$_SESSION['REDIRECT'] = 'purchases';

if (!isset($_SESSION['user'])) {
    header( 'Location: http://icsproject.jasonfavrod.com/login' );
}
?>

<div class="col-md-7 col-md-offset-2">
  <h3 class="table-title">Purchases</h3>
  <table id="purchases-table" class="table table-bordered table-hover">
    <tr>
      <th id="buyer-th">Buyer</th>
      <th id="piece-th">Piece</th>
      <th id="paid-th">Amount</th>
    </tr>
    
    <tr>
      <td><select id="buyer"></select></td>
      <td><select id="piece"></select></td>
      <td><input id="paid" type="input"> <button id="enter-purchase" class="btn btn-primary">✓</button></td>
    </tr>

  </table>

</div>

<script src="js/purchases.js"></script>
