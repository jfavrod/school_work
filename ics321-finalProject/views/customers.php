<?php
$_SESSION['REDIRECT'] = 'customers';

if (!isset($_SESSION['user'])) {
    header( 'Location: http://icsproject.jasonfavrod.com/login' );
}
?>

<div class="col-md-8 col-md-offset-2">
  <h3 class="table-title">Customers</h3>
  <table id="customers-table" class="table table-bordered table-hover">
    <tr>
        <th id="customer-name-th">Name</th>
        <th id="customer-street-th">Street</th>
        <th id="customer-city-th">City</th>
        <th id="customer-state-th">State</th>
        <th id="customer-zip-th">Zip</th>
        <th id="customer-spent-th">Spent</th>
    </tr>

    <tr>
      <td><input id="customer-name" class="input-wide" type="text"></td>
      <td><input id="customer-street" class="input-wide" type="text"></td>
      <td><input id="customer-city" class="input-wide" type="text"></td>
      <td><select id="customer-state"></select></td>
      <td><input id="customer-zip" type="text"></td>
      <td><button id="enter-customer" class="btn btn-primary">✓</button></td>
    </tr>

  </table>

</div>

<script src="/js/customers.js"></script>