<script setup>
  // imports
</script>

<style scoped>
  .wrapper {
    margin-top: 0;
  }
</style>


<template>
  <div class="wrapper">
    <h2> Your Digital Pension System </h2>


    <!-- Personal Information Section -->
    <h3> Your Personal Information </h3>
    <div class="form-group">
      <label for="name"> Nume: </label>
      <input type="text" class="form-control" id="name" v-model="nume">
    </div>
    <div class="form-group">
      <label for="surname"> Prenume: </label>
      <input type="text" class="form-control" id="surname" v-model="prenume">
    </div>
    <div class="form-group" style="display: flex; flex-direction: row;">
      <label> Gen: </label>
      <div class="form-check">
        <input class="form-check-input" type="radio" id="male" value="M" v-model="gen">
        <label class="form-check-label" for="male"> M </label>
      </div>
      <div class="form-check">
        <input class="form-check-input" type="radio" id="female" value="F" v-model="gen">
        <label class="form-check-label" for="female"> F </label>
      </div>
    </div>
    <label for="dataNastere"> Data de nastere: </label>
    <input type="date" id="dataNastere" v-model="dataNastere" required><br><br>
    <div class="form-group">
      <label for="idnp">IDNP:</label>
      <input type="text" class="form-control" id="idnp" v-model="IDNP">
    </div>
    <button> Save </button>
    <!-- End of Section -->


    <h4>Selecteaza tipul de pensie</h4>
    <select v-model="selectedOption">
      <option value="">-</option>
      <option value="option1"> pensie pentru limita de varsta </option>
      <option value="option2"> pensie pentru invaliditate </option>
      <option value="option3"> pensie de urmas </option>
      <option value="option4"> pensie pentru angajati aviatia civila </option>
      <option value="option5"> pensie pentru angajati domeniul culturii </option>
    </select>


    <div v-if="selectedOption === 'option1'">
      <h4> Ai selectat sa calculezi pensia pentru limita de varsta </h4>
      <form @submit.prevent="calculatePensieLimitaDeVarsta">
        <label for="cotizare1"> Stagiul de cotizare pana la 01.01.1999: </label>
        <input type="number" id="cotizare1" v-model="cotizare1" required><br><br>

        <label for="cotizare2"> Stagiul de cotizare dupa 01.01.1999: </label>
        <input type="number" id="cotizare2" v-model="cotizare2" required><br><br>

        <label for="venitLunar"> Venitul mediu lunar asigurat: </label>
        <input type="number" step="0.01" id="venitLunar" v-model="venitLunar" required><br><br>

        <label for="dataPensionare"> Data pensionarii: </label>
        <input type="date" id="dataPensionare" v-model="dataPensionare" required><br><br>

        <label for="varstaPensionare"> Varsta pensionarii: </label>
        <input type="number" id="varstaPensionare" v-model="varstaPensionare" required><br><br>

        <button type="submit"> Calculate </button>
      </form>

      <div style="display: flex; flex-direction: row;">
        <div v-if="result !== null">
          <h3> Valoarea pensiei: </h3>
          <p> {{ result }} MDL</p>
        </div>
        <button @click="addPerson"> Add Person </button>
      </div>
    </div>

    <div v-if="selectedOption === 'option2'">
      <h4> Ai selectat sa calculezi pensia pentru invaliditate </h4>
      <form @submit.prevent="calculatePensieInvaliditate">

        <label for="cotizare"> Stagiul de cotizare: </label>
        <input type="number" id="cotizare" v-model="cotizare" required><br><br>

        <label> Grad de dizabilitate: </label><br>
        <input type="radio" id="typeI" name="gradDizabilitate" value="I" v-model="gradDizabilitate">
        <label for="typeI">I</label><br>
        <input type="radio" id="typeII" name="gradDizabilitate" value="II" v-model="gradDizabilitate">
        <label for="typeII">II</label><br>
        <input type="radio" id="typeIII" name="gradDizabilitate" value="III" v-model="gradDizabilitate">
        <label for="typeIII">III</label><br><br>

        <label for="venitLunar"> Venitul mediu lunar asigurat: </label>
        <input type="number" step="0.01" id="venitLunar" v-model="venitLunar" required><br><br>

        <button type="submit">  Calculate</button>
      </form>

      <div style="display: flex; flex-direction: row;">
        <div v-if="result !== null">
          <h3> Valoarea pensiei: </h3>
          <p> {{ result }} MDL</p>
        </div>
        <button @click="addPerson"> Add Person </button>
      </div>
    </div>



    <div v-if="selectedOption === 'option3'">
      <h4> Ai selectat sa calculezi pensia pentru urmas </h4>
      <form @submit.prevent="calculatePensieUrmas">

        <label for="nrUrmasi"> Numarul de urmasi: </label>
        <input type="number" id="nrUrmasi" v-model="nrUrmasi" required><br><br>

        <label for="valoarePensiePredecesor"> Valoarea de pensie a predecesorului: </label>
        <input type="number" step="0.01" id="valoarePensiePredecesor" v-model="valoarePensiePredecesor" required><br><br>

        <button type="submit">  Calculate</button>
      </form>

      <div style="display: flex; flex-direction: row;">
        <div v-if="result !== null">
          <h3> Valoarea pensiei: </h3>
          <p> {{ result }} MDL</p>
        </div>
        <button @click="addPerson"> Add Person </button>
      </div>
    </div>



    <div v-if="selectedOption === 'option4'">
      <h4> Ai selectat sa calculezi pensia pentru angajati aviatia civila </h4>
      <form @submit.prevent="calculatePensieAviatiaCivila">

        <label for="venitLunar"> Venitul mediu lunar asigurat: </label>
        <input type="number" step="0.01" id="venitLunar" v-model="venitLunar" required><br><br>

        <button type="submit">  Calculate</button>
      </form>

      <div style="display: flex; flex-direction: row;">
        <div v-if="result !== null">
          <h3> Valoarea pensiei: </h3>
          <p> {{ result }} MDL</p>
        </div>
        <button @click="addPerson"> Add Person </button>
      </div>
    </div>




    <div v-if="selectedOption === 'option5'">
      <h4> Ai selectat sa calculezi pensia pentru angajati domeniul culturii </h4>
      <form @submit.prevent="calculatePensieDomeniulCulturii">

        <label for="aniActivitate"> Ani de activitate: </label>
        <input type="number" id="aniActivitate" v-model="aniActivitate" required><br><br>

        <label> Domeniu: </label><br>
        <input type="radio" id="domeniu1" name="domeniuActivitate" value="1" v-model="domeniuActivitate">
        <label for="typeI"> Artiştii de balet, artiştii din ansamblurile profesioniste de dansuri </label><br>
        <input type="radio" id="domeniu2" name="domeniuActivitate" value="2" v-model="domeniuActivitate">
        <label for="typeII"> Artiştii de circ, instrumentiştii suflători (instrumente aerofone) </label><br>

        <button type="submit">  Calculate</button>
      </form>

      <div style="display: flex; flex-direction: row;">
        <div v-if="result !== null">
          <h3> Valoarea pensiei: </h3>
          <p> {{ result==1 ? "calificat" : "respins" }} </p>
        </div>
        <button @click="addPerson"> Add Person </button>
      </div>
    </div>
    


    <!-- table of info -->
    <table class="table">
      <thead>
        <tr>
          <th>Nr.</th>
          <th>Nume</th>
          <th>Prenume</th>
          <th>Gen</th>
          <th>IDNP</th>
          <th>Data de nastere</th>
          <th>Pensie</th>
        </tr>
      </thead>
      <tbody>
        <tr v-for="(person, index) in persons" :key="person.id">
          <td>{{ index + 1 }}. </td>
          <td>{{ person.nume }}</td>
          <td>{{ person.prenume }}</td>
          <td>{{ person.gen }}</td>
          <td>{{ person.idnp }}</td>
          <td>{{ person.dataNastere }}</td>
          <td>{{ person.pensie }}</td>
        </tr>
      </tbody>
    </table>

    <div>
      <h5> Sort Pension Beneficiaries </h5>
      <div>
        <label for="sortCriterion"> By: </label>
        <select v-model="sortCriterion" id="sortBy">
          <option value="pensie" name="sortCriterion"> Pensie </option>
          <option value="idnp" name="sortCriterion"> IDNP </option>
          <option value="nume" name="sortCriterion"> Nume </option>
        </select>
      </div>
      <div>
        <label for="order"> Order: </label>
        <select v-model="sortOrder" id="order">
          <option value="ascending" name="sortOrder"> Ascending </option>
          <option value="descending" name="sortOrder"> Descending </option>
        </select>
      </div>
      <button @click="sortPersons"> Sort </button>
    </div>
  </div>

</template>

<script>
  export default {
    data () {
      return {
        nume: null,
        prenume: null,
        gen: null,
        IDNP: null,
        dataNastere: null,
        cotizare1: null,
        cotizare2: null,
        cotizare: null,
        venitLunar: null,
        dataPensionare: null,
        result: null,
        nrUrmasi: null,
        valoarePensiePredecesor: null,
        selectedOption: "",
        varstaPensionareFemei: 59,
        varstaPensionareBarbati: 63,
        varstaPensionare: null,
        sortOrder: null,
        sortCriterion: null,
        persons: [
          { id: 1, nume: 'John', prenume: 'Doe', gen: 'M', idnp: '123456789', dataNastere: '1990-01-01', pensie: 5000.05 },
          { id: 2, nume: 'Jane', prenume: 'Smith', gen: 'F', idnp: '987654321', dataNastere: '1995-05-15', pensie: 6000.99 },
          { id: 3, nume: 'Michael', prenume: 'Johnson', gen: 'M', idnp: '246813579', dataNastere: '1985-07-20', pensie: 4500.75 },
          { id: 4, nume: 'Emily', prenume: 'Brown', gen: 'F', idnp: '135792468', dataNastere: '1982-03-10', pensie: 7000.25 },
          { id: 5, nume: 'David', prenume: 'Williams', gen: 'M', idnp: '369852147', dataNastere: '1978-11-30', pensie: 5500.30 },
          { id: 6, nume: 'Jessica', prenume: 'Jones', gen: 'F', idnp: '852741963', dataNastere: '1992-09-25', pensie: 6200.50 },
          { id: 7, nume: 'Matthew', prenume: 'Davis', gen: 'M', idnp: '987123654', dataNastere: '1970-12-05', pensie: 4800.80 },
          { id: 8, nume: 'Sophia', prenume: 'Martinez', gen: 'F', idnp: '741852963', dataNastere: '1965-04-15', pensie: 6800.40 },
        ],
      }
    }, 
    methods: {
      calculatePensieLimitaDeVarsta() {
        // difference in years
        const inputDate = new Date(this.dataPensionare);
        const today = new Date();
        const diffMilliseconds = today - inputDate;
        const diffYears = diffMilliseconds / (1000 * 60 * 60 * 24 * 365.25);
        let pensReala = this.varstaPensionare;
        //
        let stagiuMinim;
        if (this.gen === "M") stagiuMinim = 39; else stagiuMinim = 37;
        let varstaPensionare;
        if (this.gen === "M") varstaPensionare = this.varstaPensionareBarbati; 
        else varstaPensionare = this.varstaPensionareFemei;
        //
        this.result = ((0.014 * 30 + 0.02 * (this.cotizare1 + this.cotizare2 - stagiuMinim) + 0.02 * (pensReala - varstaPensionare)) * this.venitLunar).toFixed(2);
      }, 
      calculatePensieInvaliditate() {
        let pensionare;
        if (this.gen === "M") pensionare = this.varstaPensionareBarbati;
        else pensionare = this.varstaPensionareFemei;
        let stagiuTotal = pensionare - 18; 
        if (this.gradDizabilitate == "I") {
          this.result = (0.42 * this.venitLunar + this.cotizare / stagiuTotal * this.venitLunar * 0.1).toFixed(2);
        } else if (this.gradDizabilitate == "II") {
          this.result = (0.35 * this.venitLunar + this.cotizare / stagiuTotal * this.venitLunar * 0.1).toFixed(2);
        } else if (this.gradDizabilitate == "III") {
          this.result = (0.20 * this.venitLunar + this.cotizare / stagiuTotal * this.venitLunar * 0.1).toFixed(2);
        }
      }, 
      calculatePensieUrmas() {
        if (this.nrUrmasi == 1) {
          this.result = (this.valoarePensiePredecesor * 0.50).toFixed(2);
        } else if (this.nrUrmasi == 2) {
          this.result = (this.valoarePensiePredecesor * 0.75).toFixed(2);
        } else {
          this.result = (this.valoarePensiePredecesor * 1.00).toFixed(2);
        }
      },
      calculatePensieAviatiaCivila() {
        this.result = (this.venitLunar * 0.35).toFixed(2);
      },
      calculatePensieDomeniulCulturii() {
        if (this.aniActivitate >= 20 && this.domeniuActivitate === "1") {
          this.result = 1;
        } else if (this.aniActivitate >= 25 && this.domeniuActivitate === "2") {
          this.result = 1;
        } else {
          this.result = 0;
        }
      },
      addPerson() {
        let pensie = this.result;
        if (pensie == 1) pensie = "calificat";
        if (pensie == 0) pensie = "respins";
        this.persons.push(
        {
          id: this.persons.length + 1, 
          nume: this.nume, 
          prenume: this.prenume, 
          gen: this.gen,
          idnp: this.IDNP, 
          dataNastere: this.dataNastere,
          pensie: pensie,
        });
        this.result = null;
        this.nume = null;
        this.prenume = null;
        this.gen = null;
        this.dataNastere = null;
        this.IDNP = null;
      },
      sortPersons() {
        let myArray = this.persons;
        if (this.sortOrder == "ascending") {
          myArray = myArray.sort((a,b) => {
            let fa, fb;
            if (this.sortCriterion == "pensie") {
              fa = a.pensie; fb = b.pensie;
            } else if (this.sortCriterion == "nume") {
              fa = a.nume; fb = b.nume;
            } else if (this.sortCriterion == "idnp") {
              fa = a.idnp; fb = b.idnp;
            }
            if (fa < fb) return -1;
            if (fa > fb) return 1;
          });
        } else {
          myArray = myArray.sort((a,b) => {
            let fa, fb;
            if (this.sortCriterion == "pensie") {
              fa = a.pensie; fb = b.pensie;
            } else if (this.sortCriterion == "nume") {
              fa = a.nume; fb = b.nume;
            } else if (this.sortCriterion == "idnp") {
              fa = a.idnp; fb = b.idnp;
            }
            if (fa > fb) return -1;
            if (fa < fb) return 1;
          });
        }
        this.persons = myArray;
        console.log("hei");
        console.log(this.persons);
      },
    }
  }
</script>