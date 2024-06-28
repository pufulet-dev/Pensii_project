<script setup>
//import artihmeticModule from './functions.wasm';
import Vue from "vue";
import "./App.css";
</script>

<template>
  <div class="wrapper">
    <div class="titleWrapper">
      <h2
        class="title1"
        style="
          font-size: 66px;
          line-height: 66px;
          color: red;
          font-weight: bolder;
        "
      >
        PENSYS
      </h2>
      <h2 class="title2" style="font-size: 20px; color: black">
        YOUR DIGITAL PENSION SYSTEM
      </h2>
    </div>

    <div style="display: flex; flex-direction: row; align-items: flex-start">
      <div class="generalInfoWrapper">
        <h3 style="font-size: 16px; font-weight: 500">
          Introduceti datele cu caracter personal:
        </h3>
        <div class="form-group">
          <label for="name"> Nume: </label>
          <input
            type="text"
            required
            class="form-control"
            id="name"
            v-model="nume"
          />
        </div>
        <div class="form-group">
          <label for="surname"> Prenume: </label>
          <input
            type="text"
            required
            class="form-control"
            id="surname"
            v-model="prenume"
          />
        </div>
        <div class="form-group" style="display: flex; flex-direction: row">
          <label style="margin-right: 20px"> Gen: </label>
          <div style="display: flex; flex-direction: row; align-items: center">
            <div
              class="form-check"
              style="display: flex; flex-direction: row; margin-right: 10px"
            >
              <input
                class="form-check-input"
                type="radio"
                id="male"
                value="M"
                v-model="gen"
              />
              <label class="form-check-label" for="male"> M </label>
            </div>
            <div class="form-check" style="display: flex; flex-direction: row">
              <input
                class="form-check-input"
                type="radio"
                id="female"
                value="F"
                v-model="gen"
              />
              <label class="form-check-label" for="female"> F </label>
            </div>
          </div>
        </div>
        <label for="dataNastere"> Data de nastere: </label>
        <input
          type="date"
          required
          id="dataNastere"
          v-model="dataNastere"
        /><br /><br />
        <div class="form-group">
          <label for="idnp">IDNP:</label>
          <input type="text" class="form-control" id="idnp" v-model="IDNP" />
        </div>
        <button>Save</button>
        <h4>Selecteaza tipul de pensie</h4>
        <select v-model="selectedOption">
          <option value="option0">-</option>
          <option value="option1">pensie pentru limita de varsta</option>
          <option value="option2">pensie pentru invaliditate</option>
          <option value="option3">pensie de urmas</option>
          <option value="option4">pensie pentru angajati aviatia civila</option>
          <option value="option5">
            pensie pentru angajati domeniul culturii
          </option>
        </select>
      </div>

      <div v-if="selectedOption === 'option0'" class="pension-window-wrapper">
        <img
          src="https://images.pexels.com/photos/4386158/pexels-photo-4386158.jpeg?auto=compress&cs=tinysrgb&w=600"
          alt=""
          style="width: 330px"
        />
      </div>

      <div v-if="selectedOption === 'option1'" class="pension-window-wrapper">
        <h4 style="font-size: 16px; font-weight: 500; margin-top: 0px;">Ai selectat sa calculezi pensia pentru limita de varsta</h4>
        <form @submit.prevent="calculatePensieLimitaDeVarsta">
          <label for="cotizare1">
            Stagiul de cotizare pana la 01.01.1999:
          </label>
          <input
            type="number"
            id="cotizare1"
            v-model="cotizare1"
            required
          /><br /><br />

          <label for="cotizare2"> Stagiul de cotizare dupa 01.01.1999: </label>
          <input
            type="number"
            id="cotizare2"
            v-model="cotizare2"
            required
          /><br /><br />

          <label for="venitLunar"> Venitul mediu lunar asigurat: </label>
          <input
            type="number"
            step="0.01"
            id="venitLunar"
            v-model="venitLunar"
            required
          /><br /><br />

          <label for="dataPensionare"> Data pensionarii: </label>
          <input
            type="date"
            id="dataPensionare"
            v-model="dataPensionare"
            required
          /><br /><br />

          <label for="varstaPensionare"> Varsta pensionarii: </label>
          <input
            type="number"
            id="varstaPensionare"
            v-model="varstaPensionare"
            required
          /><br /><br />

          <button type="submit">Calculate</button>
        </form>

        <div style="display: flex; flex-direction: row">
          <div v-if="result !== null">
            <h3>Valoarea pensiei:</h3>
            <p>{{ result }} MDL</p>
            <button class="pensie-result-wrapper" @click="addPerson">
              Add Person
            </button>
          </div>
        </div>
      </div>

      <div v-if="selectedOption === 'option2'" class="pension-window-wrapper">
        <h4 style="font-size: 16px; font-weight: 500; margin-top: 0px;">Ai selectat sa calculezi pensia pentru invaliditate</h4>
        <form @submit.prevent="calculatePensieInvaliditate">
          <label for="cotizare"> Stagiul de cotizare: </label>
          <input
            type="number"
            id="cotizare"
            v-model="cotizare"
            required
          /><br /><br />

          <div style="display: flex; flex-direction: row">
            <p style="margin-right: 20px;"> Grad de dizabilitate: </p>
            <br />
            <div style="display: flex; flex-direction: row;">
              <div
                style="
                  display: flex;
                  flex-direction: row;
                  align-items: center;
                  margin-right: 10px;
                "
              >
                <input
                  type="radio"
                  id="typeI"
                  name="gradDizabilitate"
                  value="I"
                  v-model="gradDizabilitate"
                />
                <label for="typeI">I</label><br />
              </div>
              <div
                style="
                  display: flex;
                  flex-direction: row;
                  align-items: center;
                  margin-right: 10px;
                "
              >
                <input
                  type="radio"
                  id="typeII"
                  name="gradDizabilitate"
                  value="II"
                  v-model="gradDizabilitate"
                />
                <label for="typeII">II</label><br />
              </div>
              <div
                style="display: flex; flex-direction: row; align-items: center"
              >
                <input
                  type="radio"
                  id="typeIII"
                  name="gradDizabilitate"
                  value="III"
                  v-model="gradDizabilitate"
                />
                <label for="typeIII">III</label><br /><br />
              </div>
            </div>
          </div>

          <label for="venitLunar"> Venitul mediu lunar asigurat: </label>
          <input
            type="number"
            step="0.01"
            id="venitLunar"
            v-model="venitLunar"
            required
          /><br /><br />

          <button type="submit">Calculate</button>
        </form>

        <div style="display: flex; flex-direction: row">
          <div v-if="result !== null">
            <h3>Valoarea pensiei:</h3>
            <p>{{ result }} MDL</p>
            <button @click="addPerson">Add Person</button>
          </div>
        </div>
      </div>

      <div v-if="selectedOption === 'option3'" class="pension-window-wrapper">
        <h4 style="font-size: 16px; font-weight: 500; margin-top: 0px;">Ai selectat sa calculezi pensia pentru urmas</h4>
        <form @submit.prevent="calculatePensieUrmas">
          <label for="nrUrmasi"> Numarul de urmasi: </label>
          <input
            type="number"
            id="nrUrmasi"
            v-model="nrUrmasi"
            required
          /><br /><br />

          <label for="valoarePensiePredecesor">
            Valoarea de pensie a predecesorului:
          </label>
          <input
            type="number"
            step="0.01"
            id="valoarePensiePredecesor"
            v-model="valoarePensiePredecesor"
            required
          /><br /><br />

          <button type="submit">Calculate</button>
        </form>

        <div>
          <div
            v-if="result !== null"
            style="display: flex; flex-direction: column"
          >
            <h3>Valoarea pensiei:</h3>
            <p>{{ result }} MDL</p>
            <button @click="addPerson">Add Person</button>
          </div>
        </div>
      </div>

      <div v-if="selectedOption === 'option4'" class="pension-window-wrapper">
        <h4 style="font-size: 16px; font-weight: 500; margin-top: 0px;">Ai selectat sa calculezi pensia pentru angajati aviatia civila</h4>
        <form @submit.prevent="calculatePensieAviatiaCivila">
          <label for="venitLunar"> Venitul mediu lunar asigurat: </label>
          <input
            type="number"
            step="0.01"
            id="venitLunar"
            v-model="venitLunar"
            required
          /><br /><br />

          <button type="submit">Calculate</button>
        </form>

        <div style="display: flex; flex-direction: row">
          <div v-if="result !== null">
            <h3>Valoarea pensiei:</h3>
            <p>{{ result }} MDL</p>
            <button @click="addPerson">Add Person</button>
          </div>
        </div>
      </div>

      <div v-if="selectedOption === 'option5'" class="pension-window-wrapper">
        <h4 style="font-size: 16px; font-weight: 500; margin-top: 0px;">
          Ai selectat sa calculezi pensia pentru angajati domeniul culturii
        </h4>
        <form @submit.prevent="calculatePensieDomeniulCulturii">
          <label for="aniActivitate"> Ani de activitate: </label>
          <input
            type="number"
            id="aniActivitate"
            v-model="aniActivitate"
            required
          /><br /><br />

          <label> Domeniu: </label><br />
          <input
            type="radio"
            id="domeniu1"
            name="domeniuActivitate"
            value="1"
            v-model="domeniuActivitate"
          />
          <label for="typeI">
            Artiştii de balet, artiştii din ansamblurile profesioniste de
            dansuri </label
          ><br />
          <input
            type="radio"
            id="domeniu2"
            name="domeniuActivitate"
            value="2"
            v-model="domeniuActivitate"
          />
          <label for="typeII">
            Artiştii de circ, instrumentiştii suflători (instrumente aerofone) </label
          ><br />

          <button type="submit">Calculate</button>
        </form>

        <div style="display: flex; flex-direction: row">
          <div v-if="result !== null">
            <h3>Valoarea pensiei:</h3>
            <p>{{ result == 1 ? "calificat" : "respins" }}</p>
            <button @click="addPerson">Add Person</button>
          </div>
        </div>
      </div>
    </div>

    <!-- table of info -->
    <table class="tableWrapper">
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
          <td>{{ index + 1 }}.</td>
          <td>{{ person.nume }}</td>
          <td>{{ person.prenume }}</td>
          <td>{{ person.gen }}</td>
          <td>{{ person.idnp }}</td>
          <td>{{ person.dataNastere }}</td>
          <td>{{ person.pensie }} MDL</td>
        </tr>
      </tbody>
    </table>

    <div class="sortFiltersWrapper">
      <h5 style="font-size: 16px; font-weight: 500; margin-bottom: 20px;">Sort Pension Beneficiaries</h5>
      <div>
        <label for="sortCriterion"> By: </label>
        <select v-model="sortCriterion" id="sortBy">
          <option value="pensie" name="sortCriterion">Pensie</option>
          <option value="idnp" name="sortCriterion">IDNP</option>
          <option value="nume" name="sortCriterion">Nume</option>
        </select>
      </div>
      <div>
        <label for="order"> Order: </label>
        <select v-model="sortOrder" id="order">
          <option value="ascending" name="sortOrder">Ascending</option>
          <option value="descending" name="sortOrder">Descending</option>
        </select>
      </div>
      <button @click="sortPersons" style="margin-top: 20px;">Sort</button>
    </div>

    <!-- my name -->
    <p class="signName">@ Madalina CHIRPICINIC, 2024</p>
  </div>
</template>

<script>
export default {
  data() {
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
      selectedOption: "option0",
      varstaPensionareFemei: 59,
      varstaPensionareBarbati: 63,
      varstaPensionare: null,
      sortOrder: null,
      sortCriterion: null,
      web_assembly_result: null, // from web assembly
      persons: [
        {
          id: 1,
          nume: "John",
          prenume: "Doe",
          gen: "M",
          idnp: "123456789",
          dataNastere: "1990-01-01",
          pensie: 5000.05,
        },
        {
          id: 2,
          nume: "Jane",
          prenume: "Smith",
          gen: "F",
          idnp: "987654321",
          dataNastere: "1995-05-15",
          pensie: 6000.99,
        },
        {
          id: 3,
          nume: "Michael",
          prenume: "Johnson",
          gen: "M",
          idnp: "246813579",
          dataNastere: "1985-07-20",
          pensie: 4500.75,
        },
        {
          id: 4,
          nume: "Emily",
          prenume: "Brown",
          gen: "F",
          idnp: "135792468",
          dataNastere: "1982-03-10",
          pensie: 7000.25,
        },
        {
          id: 5,
          nume: "David",
          prenume: "Williams",
          gen: "M",
          idnp: "369852147",
          dataNastere: "1978-11-30",
          pensie: 5500.3,
        },
        {
          id: 6,
          nume: "Jessica",
          prenume: "Jones",
          gen: "F",
          idnp: "852741963",
          dataNastere: "1992-09-25",
          pensie: 6200.5,
        },
        {
          id: 7,
          nume: "Matthew",
          prenume: "Davis",
          gen: "M",
          idnp: "987123654",
          dataNastere: "1970-12-05",
          pensie: 4800.8,
        },
        {
          id: 8,
          nume: "Sophia",
          prenume: "Martinez",
          gen: "F",
          idnp: "741852963",
          dataNastere: "1965-04-15",
          pensie: 6800.4,
        },
      ],
    };
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
      if (this.gen === "M") stagiuMinim = 39;
      else stagiuMinim = 37;
      let varstaPensionare;
      if (this.gen === "M") varstaPensionare = this.varstaPensionareBarbati;
      else varstaPensionare = this.varstaPensionareFemei;
      //
      this.result = (
        (0.014 * 30 +
          0.02 * (this.cotizare1 + this.cotizare2 - stagiuMinim) +
          0.02 * (pensReala - varstaPensionare)) *
        this.venitLunar
      ).toFixed(2);
    },
    calculatePensieInvaliditate() {
      let pensionare;
      if (this.gen === "M") pensionare = this.varstaPensionareBarbati;
      else pensionare = this.varstaPensionareFemei;
      let stagiuTotal = pensionare - 18;
      if (this.gradDizabilitate == "I") {
        this.result = (
          0.42 * this.venitLunar +
          (this.cotizare / stagiuTotal) * this.venitLunar * 0.1
        ).toFixed(2);
      } else if (this.gradDizabilitate == "II") {
        this.result = (
          0.35 * this.venitLunar +
          (this.cotizare / stagiuTotal) * this.venitLunar * 0.1
        ).toFixed(2);
      } else if (this.gradDizabilitate == "III") {
        this.result = (
          0.2 * this.venitLunar +
          (this.cotizare / stagiuTotal) * this.venitLunar * 0.1
        ).toFixed(2);
      }
    },
    calculatePensieUrmas() {
      if (this.nrUrmasi == 1) {
        this.result = (this.valoarePensiePredecesor * 0.5).toFixed(2);
      } else if (this.nrUrmasi == 2) {
        this.result = (this.valoarePensiePredecesor * 0.75).toFixed(2);
      } else {
        this.result = (this.valoarePensiePredecesor * 1.0).toFixed(2);
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
      this.persons.push({
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
        myArray = myArray.sort((a, b) => {
          let fa, fb;
          if (this.sortCriterion == "pensie") {
            fa = a.pensie;
            fb = b.pensie;
          } else if (this.sortCriterion == "nume") {
            fa = a.nume;
            fb = b.nume;
          } else if (this.sortCriterion == "idnp") {
            fa = a.idnp;
            fb = b.idnp;
          }
          if (fa < fb) return -1;
          if (fa > fb) return 1;
        });
      } else {
        myArray = myArray.sort((a, b) => {
          let fa, fb;
          if (this.sortCriterion == "pensie") {
            fa = a.pensie;
            fb = b.pensie;
          } else if (this.sortCriterion == "nume") {
            fa = a.nume;
            fb = b.nume;
          } else if (this.sortCriterion == "idnp") {
            fa = a.idnp;
            fb = b.idnp;
          }
          if (fa > fb) return -1;
          if (fa < fb) return 1;
        });
      }
      this.persons = myArray;
      console.log("hei");
      console.log(this.persons);
    },
  },
};
</script>
