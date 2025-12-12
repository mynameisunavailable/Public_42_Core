*This project has been created as part of the 42 curriculum by [yunguo].*

# Born2BeRoot

## 📝 Description

**Born2BeRoot** is a system administration project that serves as an introduction to virtualization and server configuration. The goal of this project is to create a secure, highly restricted virtual machine (VM) from scratch.

This project requires setting up an operating system (Debian or Rocky), implementing strict password policies, configuring a firewall, managing users and groups with specific privileges, and creating a monitoring script. It enforces a deep understanding of the Linux file system, LVM partitioning, and the basics of system security.

## 🛠️ Instructions

To evaluate this project, you must have the specific `.vdi` file and its signature.

1.  **Clone the Repository:**
    Ensure you have the `signature.txt` file from this repository.
    ```bash
    git clone [Link_To_Your_Repo]
    ```

2.  **Verify Signature:**
    Compare the signature of the `.vdi` file provided (on the USB or local storage) with the one in the repo.
    ```bash
    diff signature.txt <(shasum born2beroot.vdi | awk '{print $1}')
    ```

3.  **Launch the VM:**
    * Open VirtualBox.
    * Create a new machine and attach the existing `.vdi` file as the hard disk.
    * Start the machine.

4.  **Login:**
    * The machine boots into a CLI environment (no GUI).
    * Login using the non-root user credentials provided during the defense.
    * SSH Access: Connect via port 4242.
        ```bash
        ssh [user]@localhost -p 4242
        ```

## ⚙️ Project Description & Design Choices

### Operating System Choice: Debian
For this project, I chose **Debian** over Rocky Linux.
* **Pros:** Debian is known for its stability ("Stable" branch) and has a massive package repository. It uses the `apt` (Advanced Package Tool) which is user-friendly and standard in the 42 curriculum.
* **Cons:** Software versions in the stable branch can be older compared to rolling release distros.

### Main Design Choices
* **Partitioning:** I utilized encrypted **LVM (Logical Volume Manager)**. This allows for dynamic resizing of partitions and enhances security by encrypting the data at rest.
* **Security:**
    * **Password Policy:** Enforced via `libpam-pwquality` to require strong, complex passwords (uppercase, lowercase, digits, no repetition).
    * **Sudo:** Restricted privileges with logging enabled in `/var/log/sudo/`.
    * **SSH:** Root login disabled, default port changed to 4242 to avoid automated bot scripts on port 22.
* **Firewall:** **UFW** is enabled to block all incoming connections except for port 4242.

### Comparisons

#### 1. Debian vs Rocky Linux
* **Debian:** Uses the `.deb` package format and `apt`/`aptitude` managers. It is community-driven and adheres strictly to the GNU free software guidelines.
* **Rocky Linux:** A downstream rebuild of RHEL (Red Hat Enterprise Linux). It uses `.rpm` packages and `dnf`/`yum`. It is enterprise-focused, aiming for bug-for-bug compatibility with RHEL. Rocky uses SELinux by default, whereas Debian defaults to AppArmor.

#### 2. AppArmor vs SELinux
* **AppArmor (Application Armor):** Default on Debian. It binds access control attributes to **programs (paths)** rather than individual files. It is generally considered easier to configure and learn for beginners.
* **SELinux (Security-Enhanced Linux):** Default on Rocky/RHEL. It uses a labeling system (inodes) for files and processes. It is very granular and powerful but has a steeper learning curve and is harder to troubleshoot.

#### 3. UFW vs Firewalld
* **UFW (Uncomplicated Firewall):** A user-friendly command-line interface for `iptables` (or `nftables`). It simplifies the process of configuring a firewall, designed for ease of use on Debian/Ubuntu systems.
* **Firewalld:** A dynamic firewall manager with support for network/firewall zones. It allows modifying rules without restarting the firewall daemon and is the default on RHEL/Rocky.

#### 4. VirtualBox vs UTM
* **VirtualBox:** A Type-2 hypervisor mainly for x86/x64 architecture. It is the standard for 42 projects, offers easy snapshot management, and is open-source (GPL).
* **UTM:** A virtualization software for macOS (specifically optimized for Apple Silicon M1/M2/M3 chips) that uses QEMU under the hood. It supports both virtualization (running ARM on ARM) and emulation (running x86 on ARM), though emulation is slower.

## 📚 Resources & AI Usage

### Resources
* [Debian Administrator's Handbook](https://debian-handbook.info/)
* [Sudo Manual](https://www.sudo.ws/docs/man/)
* [UFW Documentation](https://wiki.ubuntu.com/UncomplicatedFirewall)
* [LVM Guide](https://tldp.org/HOWTO/LVM-HOWTO/)

### AI Usage Declaration
**AI tools used:** [Gemini]
**Purpose:**
* **Concept Explanation:** AI was used to create a guide to set up the VM, and to clarify various concepts encounter during the setup.
* **Debugging:** AI assisted in debugging website setup, Cron, and `monitoring.sh`.
* **Documentation:** AI helped generate the structure of this README file.
