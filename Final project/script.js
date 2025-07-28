function startComparison() {
  const arrayInput = document.getElementById("arrayInput").value;
  const target = parseInt(document.getElementById("targetInput").value);
  const array = arrayInput.split(',').map(Number);

  document.getElementById("linearBoxes").innerHTML = "";
  document.getElementById("linearExplanation").innerText = "";
  document.getElementById("binaryBoxes").innerHTML = "";
  document.getElementById("binaryExplanation").innerText = "";
  document.getElementById("comparisonTable").innerHTML = "";

  if (!arrayInput || isNaN(target)) {
    alert("Please enter valid input.");
    return;
  }

  // ===== LINEAR SEARCH TABLE =====
  const linearContainer = document.getElementById("linearBoxes");
  let linearTable = "<table class='array-table'><tr>";
  array.forEach((val, i) => {
    linearTable += `<td id='linear-${i}' class='array-cell'>${val}</td>`;
  });
  linearTable += "</tr><tr>";
  array.forEach((val, i) => {
    linearTable += `<td class='index-cell'>${i}</td>`;
  });
  linearTable += "</tr></table>";
  linearContainer.innerHTML = linearTable;

  // ===== LINEAR SEARCH STEPS =====
  let linearSteps = 0;
  let linearFound = -1;
  let linearText = "";

  for (let i = 0; i < array.length; i++) {
    linearSteps++;
    const cell = document.getElementById(`linear-${i}`);
    cell.style.backgroundColor = "#fff3cd";

    linearText += `🔎 Step ${linearSteps}:\n`;
    linearText += `➡️ Checking index ${i} where value is ${array[i]}\n`;
    linearText += `❓ Is ${array[i]} equal to ${target}? → ${array[i] === target ? "✅ Yes, target found!" : "❌ No, continue searching"}\n\n`;

    if (array[i] === target) {
      cell.style.backgroundColor = "#c8e6c9";
      linearFound = i;
      break;
    }
  }

  if (linearFound === -1) {
    linearText += `🛑 The number ${target} was not found in the array.\n`;
  }

  document.getElementById("linearExplanation").innerText = linearText;

  // ===== BINARY SEARCH TABLE =====
  const sorted = [...array].sort((a, b) => a - b);
  const binaryContainer = document.getElementById("binaryBoxes");
  let binaryTable = "<table class='array-table'><tr>";
  sorted.forEach((val, i) => {
    binaryTable += `<td id='binary-${i}' class='array-cell'>${val}</td>`;
  });
  binaryTable += "</tr><tr>";
  sorted.forEach((val, i) => {
    binaryTable += `<td class='index-cell'>${i}</td>`;
  });
  binaryTable += "</tr></table>";
  binaryContainer.innerHTML = binaryTable;

  // ===== BINARY SEARCH STEPS =====
  let binarySteps = 0;
  let binaryFound = -1;
  let binaryText = "";

  let left = 0, right = sorted.length - 1;

  while (left <= right) {
    binarySteps++;
    const mid = Math.floor((left + right) / 2);
    const cell = document.getElementById(`binary-${mid}`);
    cell.style.backgroundColor = "#fff3cd";

    binaryText += `🔎 Step ${binarySteps}:\n`;
    binaryText += `➡️ Left index = ${left}, Right index = ${right}\n`;
    binaryText += `➡️ Middle index = (${left} + ${right}) / 2 = ${mid}\n`;
    binaryText += `➡️ Value at middle index ${mid} is ${sorted[mid]}\n`;
    binaryText += `❓ Is ${sorted[mid]} equal to ${target}? → ${sorted[mid] === target ? "✅ Yes, target found!" : "❌ No, keep going"}\n`;

    if (sorted[mid] === target) {
      cell.style.backgroundColor = "#c8e6c9";
      binaryFound = mid;
      break;
    } else if (sorted[mid] < target) {
      binaryText += `➡️ Since ${sorted[mid]} is less than ${target}, move to the right half.\n`;
      binaryText += `🧭 Update Left index to ${mid + 1}\n\n`;
      left = mid + 1;
    } else {
      binaryText += `➡️ Since ${sorted[mid]} is greater than ${target}, move to the left half.\n`;
      binaryText += `🧭 Update Right index to ${mid - 1}\n\n`;
      right = mid - 1;
    }
  }

  if (binaryFound === -1) {
    binaryText += `🛑 The number ${target} was not found in the array.\n`;
  }

  document.getElementById("binaryExplanation").innerText = binaryText;

  // ===== COMPARISON SUMMARY =====
  const comparisonHTML = `
    <table border="1" cellpadding="10" style="width:100%; border-collapse: collapse;">
      <tr>
        <th>Criteria</th>
        <th>Linear Search</th>
        <th>Binary Search</th>
      </tr>
      <tr>
        <td>Steps Taken</td>
        <td>${linearSteps}</td>
        <td>${binarySteps}</td>
      </tr>
      <tr>
        <td>Target Found?</td>
        <td>${linearFound !== -1 ? `✅ Yes (Index ${linearFound})` : "❌ No"}</td>
        <td>${binaryFound !== -1 ? `✅ Yes (Index ${binaryFound})` : "❌ No"}</td>
      </tr>
      <tr>
        <td>Array Sorted?</td>
        <td>No</td>
        <td>Yes (automatically sorted)</td>
      </tr>
    </table>
  `;
  let explanation = "";

if (linearFound !== -1 && binaryFound !== -1) {
  if (linearSteps < binarySteps) {
    explanation += "📌 In this case, Linear Search found the target in fewer steps. This can happen when the array is unsorted and the target is near the beginning.\n\n";
  } else if (binarySteps < linearSteps) {
    explanation += "📌 Binary Search was more efficient in this case, taking fewer steps because the array is sorted and the algorithm can eliminate half of the remaining elements at each step.\n\n";
  } else {
    explanation += "📌 Both algorithms took the same number of steps to find the target in this case.\n\n";
  }
} else if (linearFound !== -1 && binaryFound === -1) {
  explanation += "📌 The target was found by Linear Search but not by Binary Search. This is likely because the original array was unsorted, and Binary Search relies on sorted input to work correctly.\n\n";
} else if (linearFound === -1 && binaryFound !== -1) {
  explanation += "📌 Binary Search found the target but Linear Search did not. This is rare and might indicate a problem with how the array was read or interpreted.\n\n";
} else {
  explanation += "📌 Neither algorithm found the target. Double-check your input values.\n\n";
}

explanation += "💡 Binary Search is faster in general but only works correctly on sorted arrays. If the array is unsorted and you can't sort it beforehand, Linear Search is your only option.\n\n";
explanation += "📍 Example scenario where Linear Search is better: \nSuppose you're searching for a large number like 99 that is located near the start of an unsorted array. Binary Search would sort the array and place 99 near the end, making it slower to find, while Linear Search might find it quickly.\n";

document.getElementById("comparisonTable").innerHTML = `
  ${comparisonHTML}
  <pre class="step-text" style="margin-top: 20px;">${explanation}</pre>
`;

}
